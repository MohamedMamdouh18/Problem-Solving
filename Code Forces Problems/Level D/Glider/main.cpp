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
 
 
void solve() {
    ll n, height;
    cin >> n >> height;
    vector<pair<ll, ll>> a(n);
    vector<ll> b;
    for (int i = 0; i < n; ++i) cin >> a[i].fi >> a[i].se;
    for (int i = 0; i < n; ++i) {
        b.pb(a[i].se - a[i].fi);
        if (i != n - 1) b.pb(a[i].se - a[i + 1].fi);
    }
    ll r = 0, ans = LONG_LONG_MIN, sum = 0, notComplete = 0 , subHeight , addSum;
    for (int l = 0; l < b.size(); ++l) {
        while (height > 0) {
            if(notComplete){
                sum -= addSum ;
                height += subHeight ;
                r -- ;
                notComplete = 0 ;
            }
            if (r < b.size()) {
                if (b[r] > 0) sum += b[r];
                else {
                    if(height < -b[r]){
                        notComplete = 1 ;
                        addSum = height ;
                        subHeight = height ;
                        sum += height ;
                        height = 0 ;
                    }else{
                        height += b[r] ;
                        sum -= b[r] ;
                    }
                }
                r++;
            } else {
                sum += height;
                height = 0;
            }
        }
        ans = max(ans, sum);
        if (r >= b.size()) break;
        height = height - b[l + 1];
        sum = sum - b[l] + b[l + 1];
        l++;
    }
    cout << ans;
}
 
int main() {
    IOS
    PREC
 
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
