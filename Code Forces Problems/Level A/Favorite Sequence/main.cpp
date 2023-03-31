#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int t , n ;
    cin >> t ;
    while(t --)
    {
        cin >> n ;
        vector <int> a(n) ;
        vector <int> b(n) ;
        rep(i , 0 , n)
        {
            cin >> a[i] ;
        }
        int l = 0 , r = n - 1 , order = 0 ;
        while(order < n)
        {
            b[order] = a[l] ;
            l ++;
            order ++;
            b[order] = a[r] ;
            r --;
            order ++;
        }
        rep(i , 0 , n)
        {
            cout << b[i] << " " ;
        }
        cout << endl ;
    }
}
