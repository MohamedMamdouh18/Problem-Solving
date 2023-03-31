#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    ll t, n, l, r;
    cin >> t;
    while (t--) {
        ll ans = 0;
        cin >> n >> l >> r;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            auto cur = a.begin() + i;
            auto low = lower_bound(cur + 1, a.end(), l - a[i]);
            auto up = upper_bound(cur+1, a.end(), r - a[i]);
            if (low == a.end()) continue;
            ans += up - low ;

        }
        cout << ans << el ;
    }
}
