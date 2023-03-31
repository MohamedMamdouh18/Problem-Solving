#include <bits/stdc++.h>
using namespace std ;
 
#define mp make_pair
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main(){
   IOS
   ll n , m , x , y ;
   cin >> n >> m >> x >> y ;
   vector <ll> soldier(n) ;
   vector <ll> vest(m) ;
   rep(i , 0 , n) cin >> soldier[i] ;
   rep(i , 0 , m) cin >> vest[i] ;
   vector <pair<int,int>> ans ;
 
   int l = 0 ;
   rep(r , 0 , n)
   {
       if(!(soldier[r] - x <= vest[l] && vest[l] <= soldier[r] + y))
       {
           while(vest[l] <= soldier[r] + y && l < m)
           {
               l++ ;
               if(soldier[r] - x <= vest[l] && vest[l] <= soldier[r] + y) break ;
           }
       }
       if(l == m)break ;
       if(soldier[r] - x <= vest[l] && vest[l] <= soldier[r] + y)
       {
           ans.pb(mp(r+1 , l+1)) ;
           l ++ ;
       }
   }
   cout << ans.size()<<endl  ;
    rep(i , 0 ,ans.size())
    {
        cout<<ans[i].first <<" "<<ans[i].second<<endl ;
    }
}
