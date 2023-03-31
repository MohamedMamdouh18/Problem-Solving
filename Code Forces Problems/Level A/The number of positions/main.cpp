#include <bits/stdc++.h>
using namespace std ;

#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
   IOS
   int n , a , b ;
   cin >> n >> a >> b ;
   int counti = 0;
   rep(i , 0 , n )
   {
       if(i >= a && n - i - 1 <= b) counti ++ ;
   }
   cout << counti ;

}

