#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define srt(a)     (sort(a.begin() , a.end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
 
int main(){
   IOS
   ll n , s ;
   cin >> n >> s ;
   vi a(n) ;
   rep(i , 0 , n) cin >> a[i] ;
 
 
   ll l = 0 , sum = 0 , longest = 1e5;
   rep(r , 0 , n)
   {
       sum += a[r] ;
       while(sum - a[l] >= s)
       {
           sum -= a[l] ;
           l ++ ;
       }
       if (sum >= s) longest = min(longest , r-l+1) ;
   }
   if(longest == 1e5) cout << -1 ;
   else cout << longest ;
 
}
