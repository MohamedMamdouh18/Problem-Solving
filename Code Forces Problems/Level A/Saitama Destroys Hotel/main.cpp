#include <bits/stdc++.h>
using namespace std ;
 
 
#define srt(a)     (sort(a.begin() , a.end()))
#define revsrt(a)     (sort(a.rbegin() , a.rend()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main(){
   IOS
   int current_floor , n , time = 0;
   cin >> n >> current_floor ;
   vector<pair<int,int>> a(n) ;
   rep(i , 0 , n)
   {
       cin >> a[i].first >> a[i].second ;
   }
   revsrt(a) ;
 
   rep(i , 0 , n)
   {
       time += current_floor - a[i].first ;
       current_floor = a[i].first ;
       if(time < a[i].second) time += a[i].second - time  ;
   }
   time += current_floor ;
   cout << time ;
}
