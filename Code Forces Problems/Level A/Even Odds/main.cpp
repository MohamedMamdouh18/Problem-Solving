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

   ll n , k ;
   cin >> n >> k ;

   if(n%2 == 0)
   {
       if(k <= n/2) cout << k*2 - 1 ;
       else
       {
           k -= n/2 ;
           cout << k*2 ;
       }
   }
   else
   {
       if(k <= n/2+1) cout << k*2 - 1 ;
       else
       {
           k -= n/2+1 ;
           cout << k*2 ;
       }
   }

}
