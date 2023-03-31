 
#include <bits/stdc++.h>
using namespace std ;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)
 
int main() {
    IOS
    string s;
    cin >> s ;
    int sizee = s.size() ;
    int a[sizee] = {0} ;
    rep(i , 1 , sizee)
    {
        if(s[i-1] == s[i])
        {
            a[i] ++ ;
        }
        a[i] += a[i-1] ;
    }
    int n , l , r;
    cin >> n ;
    while(n--)
    {
        cin >> l >> r ;
        cout << a[r - 1] - a[l - 1] << endl ;
    }
}
