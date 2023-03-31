By MohamedMamdouh19, contest: Codeforces Global Round 19, problem: (C) Andrew and Stones, Accepted, #, Copy
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        ll n, x, ans = 0, spare = 0;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (i != 0 && i != n - 1) {
                ans += ceil((double) x / 2);
                spare += (x >= 2);
                v[i] = x;
            }
        }
        if (n == 3) {
            cout << ((!(v[1] & 1)) ? ans : -1) << el;
            continue;
        }
        if (spare > 0) cout << ans << el;
        else cout << -1 << el;
    }
}
