#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
ll gcd(ll x,ll y)
{
    if(y==0) return x;
    else return gcd(y,x%y);
}
int main() {
    IOS
    long double a , b , c , d , dom , nom , gcde;
    cin >> a >> b >> c >> d ;

    if(a/b > c/d)
    {
        nom = (a*d - c*b) ;
        dom = (a*d) ;
    }
    else if(a/b < c/d)
    {
        nom = (c*b - a*d) ;
        dom = (c*b) ;
    }
    else
    {
        cout << "0/1" ;
        return 0 ;
    }
    gcde = gcd(nom , dom) ;
    nom /= gcde ;
    dom /= gcde ;
    cout <<  (int)nom << "/" << (int)dom  ;

}
