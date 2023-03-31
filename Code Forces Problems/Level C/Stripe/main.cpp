
#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    int n , cuts = 0;
    cin >> n ;
    vector <int> a(n + 1) ;
    rep(i , 1 , n + 1 )
    {
        cin >> a[i] ;
    }

    vector <int> b(n+1) ;
    rep(i , 1 , n + 1)
    {
        b[i] = b[i-1] + a[i] ;
    }

    rep(i , 1 , n)
    {
        if(b[i] * 2 == b.back())
        {
            cuts++ ;
        }
    }
    cout << cuts ;
}
