#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define revsrt(a)     (sort(a.rbegin() , a.rend()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))

int main(){
   IOS
   int n ;
   cin >> n ;
   vector<ll> volume(n) ;
   vector<ll> capacity(n) ;
   rep(i,0,n) cin>>volume[i] ;
   rep(i,0,n) cin>>capacity[i] ;

   revsrt(capacity) ;
   ll all = sum(volume) ;
   if(all <= capacity[0] + capacity[1]) cout<<"YES" ;
   else cout<<"NO" ;

}
