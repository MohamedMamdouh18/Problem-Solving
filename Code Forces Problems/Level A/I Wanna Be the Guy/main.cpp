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
   vector<int> a ;
   int n ;
   cin >> n ;
   int vis[n+1] = {0} ;
   int p , q ,x;
   cin >> p ;
   while(p --)
   {
       cin >> x ;
       vis[x] = 1 ;
   }
   cin >> q ;
    while(q --)
   {
       cin >> x ;
       vis[x] = 1 ;
   }

   for(int i = 1 ; i < n+1 ; i++)
   {
       if(vis[i] == 0)
       {
           cout <<"Oh, my keyboard!";
           return 0 ;
       }
   }
   cout << "I become the guy.";
}
