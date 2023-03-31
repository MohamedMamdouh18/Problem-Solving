#include <bits/stdc++.h>
using namespace std ;

#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int t ;
   cin >> t;
   while(t--)
   {
       int a1,a2,b1,b2,f1,f2 , counti = 0;
       cin >>a1>>a2>>b1>>b2>>f1>>f2 ;

       if(a1 == b1 && b1 == f1 && a2 != b2 && b2 != f2)
       {
           if( (f2 < b2 && f2 < a2) || (f2 > b2 && f2 > a2) ) counti = abs(a2-b2) ;
           else counti = 2 + abs(a2-b2) ;
       }
       else if(a1 != b1 && b1 != f1 && a2 == b2 && b2 == f2)
       {
           if( (f1 < b1 && f1 < a1) || (f1 > b1 && f1 > a1) ) counti = abs(a1-b1) ;
           else counti = 2 + abs(a1-b1) ;
       }
       else counti = abs(a1 - b1) + abs(a2-b2) ;
        cout << counti << endl ;
   }

}
