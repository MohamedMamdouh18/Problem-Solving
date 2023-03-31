#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    int n , s , t , ans = 0 ;
    cin >> n >> s >> t ;
    s--,t-- ;
    vector<int> num(n) ;
    vector<bool> visited(n) ;
    for (int i = 0; i < n; ++i) {
        cin >> num[i] ;
        num[i] -- ;
    }
    visited[s] = true;
    while (s != t){
        s = num[s] ;
        ans ++ ;
        if(visited[s]){
            cout << -1 ;
            return;
        }
        visited[s] = true ;
    }
    cout << ans ;

}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
