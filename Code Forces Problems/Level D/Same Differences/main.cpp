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
    ll n, ans = 0, x;
    cin >> n;
    map<ll, ll> exist;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        exist[x - i - 1]++;
    }
    for (auto item: exist) {
        if (item.se > 1) ans += (item.se * (item.se - 1)) / 2;
    }
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
