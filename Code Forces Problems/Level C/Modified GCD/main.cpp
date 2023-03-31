#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
vector<pair<int, int> > factors;

ll factorize(ll a) {
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            factors.emplace_back(i, 0);
            while (a % i == 0) a /= i, factors.back().se++;
        }
    }
    if (a > 1) factors.emplace_back(a, 1);
    ll ans = 0;
    for (int i = 0; i < factors.size(); ++i) {
        ans += factors[i].se;
    }
    return ans;
}

vector<int> divisors;

void getDivisors(int ind = 0, int res = 1) {
    if (ind == (int) factors.size()) {
        divisors.push_back(res);
        return;
    }
    for (int i = 0; i <= factors[ind].second; i++) {
        getDivisors(ind + 1, res);
        res *= factors[ind].first;
    }
}

void GREEN() {
    ll a, b, n, l, r;
    cin >> a >> b >> n;
    factorize(a);
    getDivisors();
    auto aDivisor = vector<int>(divisors);
    factors.clear();
    divisors.clear();
    factorize(b);
    getDivisors();
    auto bDivisor = vector<int>(divisors);
    sort(all(aDivisor));
    sort(all(bDivisor));
    vector<int> common;
    set_intersection(aDivisor.begin(), aDivisor.end(), bDivisor.begin(), bDivisor.end(), inserter(common,
                                                                                                  common.begin()));
    while (n--) {
        cin >> l >> r;
        int d = *(upper_bound(all(common), r) - 1);
        if (d < l) cout << -1 << el;
        else cout << d << el;
    }

}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
