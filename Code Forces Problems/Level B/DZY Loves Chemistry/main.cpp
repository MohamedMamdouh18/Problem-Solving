#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int vis[50] = {0} ;
vector<vector<int>> adj_list(50) ;
ll n , m ,  path = 1;
 
void dfs(int node)
{
    if(vis[node]) return ;
    vis[node] = 1 ;
    for(int i = 0 ; i < adj_list[node].size() ; i ++)
    {
        int child = adj_list[node][i] ;
        if(!vis[child])
        {
            path *= 2 ;
            dfs(child) ;
        }
    }
}
 
int main(){
   IOS
   cin >> n >> m ;
   if(m == 0)
   {
       cout << 1 ;
       return 0 ;
   }
   int x , y;
   rep(i , 0 ,m)
   {
       cin >>x >> y ;
       x-- , y -- ;
       adj_list[x].pb(y) ;
       adj_list[y].pb(x) ;
   }
   rep(i , 0 , n)
   {
       if(!vis[i]) dfs(i) ;
   }
    cout << path ;
}
