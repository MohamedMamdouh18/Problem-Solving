
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
       int l = -1 , r = n ;
       bool found = false ;
       while(r > l + 1)
       {
           int mid = (l+r) /2 ;
 
           if(a[mid] < x) l = mid ;
           else r = mid  ;
       }
       cout << r+1 << endl;
   }
 
}
