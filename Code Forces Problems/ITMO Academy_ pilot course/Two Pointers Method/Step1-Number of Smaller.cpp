#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define vi vector<int>
#define coutv(a)     for(int i=0; i<a.size() ; i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define isfind(a,s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n , m ;
    cin >> n >> m ;
    vi a(n) ; vi b(m) ;
    cinv(a) ; cinv(b) ;
    vi c ;
    int l = 0 , r = 0 ;
    rep(i , 0 , m)
    {
        while(a[l] < b[r] && l < n)
        {
            l ++ ;
        }
        c.pb(l) ;
        r ++ ;
    }
   coutv(c) ;
}
