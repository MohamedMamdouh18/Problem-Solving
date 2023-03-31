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

vector<pair<int, int>> factorize(ll n) {
    vector<pair<int, int>> factors;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.emplace_back(i, 0);
            while (n % i == 0) n /= i, factors.back().se++;
        }
    }
    if (n > 1) factors.emplace_back(n, 1);
    return factors;
}

void GREEN() {
    int a, b, ans = 0;
    cin >> a >> b;
    if (a == b) {
        cout << 0;
        return;
    }
    auto aFactors = factorize(a);
    auto bFactors = factorize(b);
    int i = 0, j = 0;
    while (i < aFactors.size() && j < bFactors.size()) {
        if (aFactors[i].fi == bFactors[j].fi) {
            int moves = min(aFactors[i].se, bFactors[j].se);
            aFactors[i].se -= moves;
            bFactors[j].se -= moves;
            i++ ,j ++ ;
        } else if (aFactors[i].fi < bFactors[j].fi) i++;
        else if (aFactors[i].fi > bFactors[j].fi) j++;
    }
    for (int i = 0; i < aFactors.size(); ++i) {
        if(aFactors[i].se > 0){
            if(aFactors[i].fi > 5){
                cout << -1 ;
                return;
            }else ans += aFactors[i].se ;
        }
    }
    for (int i = 0; i < bFactors.size(); ++i) {
        if(bFactors[i].se > 0){
            if(bFactors[i].fi > 5){
                cout << -1 ;
                return;
            }else ans += bFactors[i].se ;
        }
    }
    cout << ans ;
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
