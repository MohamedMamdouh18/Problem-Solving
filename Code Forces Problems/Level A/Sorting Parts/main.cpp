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
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        vector<int> v(n) ;
        for (int i = 0; i < n; ++i) {
            cin >> v[i] ;
        }
        if(is_sorted(v.begin() , v.end())) cout << "NO" <<el ;
        else cout << "YES" << el ;
    }
}
