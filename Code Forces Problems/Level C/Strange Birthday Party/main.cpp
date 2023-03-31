#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define se second
#define fi first
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        ll n, m, x, ans = 0, flag = 1;
        cin >> n >> m;
        vector<ll> present(m);
        vector<pair<ll, ll>> guest(n);
        for (int i = 0; i < n; ++i) {
            cin >> x;
            guest[i].fi = --x;
            guest[i].se = i;
        }
        for (int i = 0; i < m; ++i) cin >> present[i];
        sort(guest.rbegin(), guest.rend());
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (present[j] < present[guest[i].fi]) ans += present[j++];
            else ans += present[guest[i].fi];
        }
        cout << ans << el;
    }
}
