#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        ll n, x, ans = 0;
        cin >> n;
 
        vector<vector<ll>> Powers(30);
        for (int i = 0; i < n; ++i) {
            cin >> x;
            Powers[(int)log2(x)].pb(x);
        }
 
        for (int i = 0; i < Powers.size(); ++i) {
            ll siz = Powers[i].size();
            ans += (siz * siz - siz) / 2;
        }
        cout << ans << "\n" ;
    }
}
