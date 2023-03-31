#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define revsrt(a)     (sort(a.rbegin() , a.rend()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll k , n ;
vector<ll> a ;

bool good(ll x)
{
    ll y = x;
	y *= k;
	rep(i , 0 , n)
	{
	    y -= min(x , a[i]) ;
	}
	return y <= 0;

}

int main(){
   IOS
   cin >>k >> n ;
   a.resize(n) ;
   rep(i , 0 , n) cin >> a[i] ;

   if(a.size() < k)
   {
       cout << 0 ;
       return 0 ;
   }
   ll l = 0 , r = 1;
   while(good(r)) r*=2 ;

   while(r > l + 1)
   {
       ll mid = (l+r) / 2 ;
       if(good(mid)) l = mid ;
       else r = mid ;
   }

   cout << l ;
}
