#include <bits/stdc++.h>
#include <math.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
   IOS
   int n ,q;
   cin >> n ;
   vi shops(n) ;
   rep(i,0,n) cin >>shops[i] ;
   cin >> q ;

   sort(shops.begin() , shops.end()) ;
    int i = 0 ;
   while(q --)
   {
       int price ;
       cin >> price ;
       int l = -1 , r = shops.size() ;
       while( r > l + 1)
       {
           int mid = (l+r) / 2;
           if(shops[mid] <= price) l = mid ;
           else r = mid ;
       }
       cout << l + 1 << endl ;
       i ++ ;
   }
}
