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
    int t;
    cin >> t;
    while (t--){
        int n , x ,ans ,valid = 0 ;
        cin >> n ;
        set<int> num ;
        vector<int> v ;
        for (int i = 0; i < n; ++i) {
            cin >> x ;
            num.insert(x) ;
            v.pb(x) ;
        }
        for (int i = 1; i < 1024; ++i) {
            int cont = 0 ;
            for (int j = 0; j < v.size(); ++j) {
                if(!(num.count(i ^ v[j]))){
                    cont = 1 ;
                    break ;
                }
            }
            if(cont) continue;
            valid = 1;
            ans = i ;
            break;
        }
        if(valid) cout << ans << el ;
        else cout << -1 << el ;
 
    }
}
