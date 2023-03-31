#include <bits/stdc++.h>
using namespace std ;

#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int n ;
   cin >> n ;
   int kills = 0 , alive = n ;
   vector<int> a(n) ;
   vector<int> b(n) ;
   rep(i,0,n) cin >> a[i] ;
 
   for(int i = n-1 ; i > 0 ; i --)
   {
       if(a[i] > kills) kills = a[i] ;
       if(kills != 0)
       {
           kills -- ;
           alive -- ;
       }
 
   }
   cout << alive ;
}
