#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int n ;
   cin >> n ;
   int x=0 , y=0, z=0 , x1 , y1 , z1;
   while(n--)
   {
       cin >> x1 >> y1 >> z1 ;
       x += x1 ;
       y += y1 ;
       z += z1 ;
   }

   if(x != 0 || y != 0 || z != 0) cout << "NO" ;
   else cout << "YES" ;
}
