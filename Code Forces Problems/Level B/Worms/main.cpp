#include <bits/stdc++.h>
#include <math.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int n , m;
   cin >> n ;
   vi a(n) ;
   rep(i , 0 , n ) cin >>a[i] ;
   rep(i , 1 , n)
   {
       a[i] += a[i-1] ;
   }

   cin >> m ;
   while(m --)
   {
       int worm ;
       cin >> worm ;
       int l = -1 , r = a.size()-1 ;
       while(r > l + 1)
       {
           int mid = (l+r) / 2;
           if(worm > a[mid]) l = mid ;
           else r = mid ;
       }
       cout << r+1 << endl ;
   }
}
