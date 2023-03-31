#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = LONG_LONG_MAX;
const double eps = 1e-6;


void GREEN() {
    ll n, k, x, index = k, maxi = 0;
    cin >> n >> k;
    map<ll, ll> mods;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        mods[x % k]++;
    }
    for (auto item: mods) {
        if (item.fi == 0) continue;
        if (item.se > maxi) {
            maxi = item.se;
            index = item.fi;
        }
    }
    if(maxi == 0 || k == 1){
        cout << 0 << el ;
        return;
    }
    ll ans = k * (maxi - 1) + 1;
    ans += k - index;
    cout << ans << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
