#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    IOS
   int n , cap = 0 , maxcap = -1 ;
   cin >> n ;
   while(n--)
   {
       int a , b ;
       cin >> a >> b ;
       cap =cap - a + b ;
       if(cap > maxcap) maxcap = cap ;
   }
   cout <<maxcap ;
}
