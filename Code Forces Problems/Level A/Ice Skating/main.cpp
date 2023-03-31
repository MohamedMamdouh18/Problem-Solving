#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<int> vis(100) ;
vector<vector<int>> adj_list(100) ;
ll n ;


void dfs(int node)
{
    if(vis[node]) return ;
    vis[node] = 1;
    rep(i , 0 , adj_list[node].size())
    {
        int child = adj_list[node][i] ;
        if(!vis[child]) dfs(child) ;
    }
}


int main(){
   IOS
   int ans = 0 , x , y;
   cin >> n ;
   vector<pair<int,int>> points(n) ;
   rep(i , 0 , n) cin >>points[i].first >> points[i].second ;

   rep(i , 0 , n)
   {
       rep(j , i+1 , n)
       {
           if(points[i].first == points[j].first || points[i].second == points[j].second)
           {
               adj_list[i].pb(j) ;
               adj_list[j].pb(i) ;
           }
       }
   }

   rep( i , 0 , n)
   {
       if(!vis[i])
       {
           ans++ ;
           dfs(i) ;
       }
   }

   cout << ans -1 ;
}
