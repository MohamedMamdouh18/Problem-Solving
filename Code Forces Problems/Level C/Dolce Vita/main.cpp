#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
vector<ll> prefix;
 
ll searchMax(int shop, ll money) {
    ll l = 0, r = money + 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (prefix[shop] + (mid - 1) * shop <= money) l = mid;
        else r = mid;
    }
    return l;
}
 
int main() {
    IOS
    PREC
    int t;
    cin >> t;
    while (t--) {
        ll n, x, ans = 0;
        cin >> n >> x;
        vector<ll> sugar(n);
        prefix.clear();
        prefix.resize(n + 1);
        for (int i = 0; i < n; ++i) cin >> sugar[i];
        sort(all(sugar));
        for (int i = 1; i < n + 1; ++i) prefix[i] = prefix[i - 1] + sugar[i - 1];
        for (int i = 1; i < n + 1; ++i) {
            int days = searchMax(i, x);
            ans += days;
            if (days == 0) break;
        }
 
 
        cout << ans << el;
    }
}
