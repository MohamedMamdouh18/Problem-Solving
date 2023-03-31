#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main(){
   IOS
   int n , k;
   cin >> n >> k;
   vi a(n) ;
   rep(i , 0 , n) cin >> a[i] ;
   rep(i , 0 , k)
   {
       int x ;
       cin >> x ;
       int l = 0 , r = n-1 ;
       bool found = false ;
       while(l <= r)
       {
           int mid = (l+r) /2 ;
           if(a[mid] == x)
           {
               found = true ;
               break ;
           }
           else if(a[mid] < x) l = mid + 1 ;
           else if(a[mid] > x) r = mid - 1 ;
       }
       if(found) cout << "YES" << endl ;
       else cout << "NO" << endl ;
   }
 
}
