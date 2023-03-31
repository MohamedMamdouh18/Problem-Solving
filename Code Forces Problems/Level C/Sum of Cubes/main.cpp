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
set<ll> cubes;

void solve() {
    ll x;
    cin >> x;
    for (ll i = 1; i * i * i <= x; ++i) {
        if(cubes.count( x - i * i * i)){
            cout << "YES" << el ;
            return;
        }
    }
    cout << "NO" << el ;
}

int main() {
    IOS
    PREC
    for (ll i = 1; i <= 10000; ++i) {
        cubes.insert(i * i * i);
    }

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
