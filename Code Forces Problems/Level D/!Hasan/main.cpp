#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


ll n , x , y ;

bool good(ll d)
{
    return  (d/x)+(d/y) >= n;
}

int main(){
   IOS
   cin >> n >> x >> y ;

   ll l = 0 ;
   ll r = 1 ;
   while(!good(r)) r*=2 ;

   while(r > l+1)
   {
       ll mid = (r+l)/2 ;
       if(good(mid)) r = mid;
       else l = mid ;
   }
   cout << r ;
}
