#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
int freq[100001] ;

void solve() {
    int n , ans = INT_MIN , siz = 0;
    cin >> n ;
    for (int i = 0; i < n * 2; ++i) {
        int x ;
        cin >> x ;
        if(freq[x] == 0){
            freq[x] = 1 ;
            siz ++ ;
        }else siz -- ;
        ans = max(ans , siz) ;
    }
    cout << ans ;
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
