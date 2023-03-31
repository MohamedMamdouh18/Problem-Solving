#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
bool good(ll x , ll w , ll h , ll n)
{
    return ((x/h)*(x/w)) >= n ;
}
 
int main(){
   IOS
   ll w , h , n ;
   cin >> w >> h >> n ;
 
   ll l = 0 ;
   ll r = 1 ;
   while(!good(r,w,h,n)) r*=2 ;
 
   while(r > l+1)
   {
       ll mid = (r+l)/2 ;
       if(good(mid , w , h , n)) r = mid;
       else l = mid ;
   }
   cout << r ;
}
