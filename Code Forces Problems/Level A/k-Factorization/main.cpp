#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

vector<pair<int, int>> factorize(ll n) {
    vector<pair<int, int>> fact;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.emplace_back(i, 0);
            while (n % i == 0) n /= i, fact.back().se++;
        }
    }
    if (n > 1) fact.emplace_back(n, 1);
    return fact;
}

ll fp(ll base, ll power) {
    if (power == 0) return 1;
    ll res = fp(base, power / 2);
    res *= res;
    if (power & 1) res *= base;
    return res;
}

void GO() {
    ll n, k, ans = 0;
    cin >> n >> k;
    auto factors = factorize(n);
    for (int i = 0; i < factors.size(); ++i) ans += factors[i].se;
    if (ans < k) cout << -1;
    else {
        ll buffer = 1, ind = 0;
        k -- ;
        while (ans - k != 0) {
            if (ans - k > factors[ind].se) {
                buffer *= fp(factors[ind].fi, factors[ind].se);
                ans -= factors[ind].se;
                factors[ind].se = 0 ;
                ind++;
            } else {
                buffer *= fp(factors[ind].fi, ans - k);
                factors[ind].se -= (ans - k);
                ans = k ;
            }
        }
        if (buffer > 1) cout << buffer << " ";
        for (int i = 0; i < factors.size(); ++i) {
            while (factors[i].se != 0) {
                cout << factors[i].fi << " ";
                factors[i].se--;
            }
        }
    }


}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
