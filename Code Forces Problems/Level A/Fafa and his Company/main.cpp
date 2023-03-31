#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    int n , ans = 0;
    cin >> n ;
    rep(i , 1 , n/2 + 1)
    {
        if((n-i) % i == 0)
        {
            ans ++ ;
        }
    }
    cout << ans ;

}
