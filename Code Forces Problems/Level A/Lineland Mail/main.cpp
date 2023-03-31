#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int n ;
    cin >> n ;
    int a[n];
    rep(i , 0 , n)
    {
        cin >> a[i] ;
    }
    if(n == 2)
    {
        cout << a[1] - a[0] << " " <<a[1] - a[0] << endl ;
        cout << a[1] - a[0] << " " <<a[1] - a[0] << endl ;
        return 0 ;
    }
 
    rep(i , 0 , n)
    {
        if(i != 0 && i != n-1 )
        {
            cout << min((a[i] - a[i-1]) , a[i+1] - a[i]) << " " ;
            cout << max((a[i] - a[0]) , a[n-1] - a[i]) << endl ;
        }
        else if(i == 0)
        {
            cout << a[1] - a[0] << " " <<a[n-1] - a[0] << endl ;
        }
        else if (i == n-1)
        {
            cout << a[n-1] - a[n-2] << " " <<a[n-1] - a[0] << endl ;
        }
 
    }
 
}
