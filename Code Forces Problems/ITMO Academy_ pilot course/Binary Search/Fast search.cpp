#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define srt(a)     (sort(a.begin() , a.end()))
 
 
int main(){
   IOS
   int n , k;
   cin >> n ;
   vi a(n) ;
   rep(i , 0 , n) cin >> a[i] ;
   srt(a) ;
   cin >> k ;
   rep(i , 0 , k)
   {
       int x  , y;
       cin >> x >> y ;
 
       int ind1 , ind2 ;
 
       int l = -1 , r = n ;
       while(r > l + 1)
       {
           int mid = (r+l) / 2 ;
           if(a[mid] < x) l = mid ;
           else r = mid ;
       }
       ind1 = r ;
       l = -1 , r = n ;
       while(r > l + 1)
       {
           int mid = (r+l) / 2 ;
           if(a[mid] <= y) l = mid ;
           else r = mid ;
       }
       ind2 = l ;
       cout << ind2 - ind1 + 1<< endl ;
   }
 
}
