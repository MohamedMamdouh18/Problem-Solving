#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
vector<int> vis(2001) ;
vector<int> mang ;
vector<vector<int>> adj_list(2001) ;
int n ,x , depth = -1;
 
void dfs(int node , int path)
{
    int visit = 0 ;
    rep(i , 0 , adj_list[node].size())
    {
        if(vis[adj_list[node][i]]) visit ++ ;
    }
    if(visit == adj_list[node].size())
    {
        depth = max(depth , path) ;
        return ;
    }
    vis[node] = 1 ;
 
    rep(i , 0 , adj_list[node].size())
    {
        int child = adj_list[node][i] ;
        if(!vis[child]) dfs(child , path + 1) ;
    }
 
}
 
int main(){
   IOS
   cin >> n ;
   rep(i , 0 , n)
   {
       cin >> x ;
       if(x == -1)
       {
           mang.pb(i) ;
           continue ;
       }
       x -- ;
       adj_list[i].pb(x) ;
       adj_list[x].pb(i) ;
   }
   rep(i , 0 , mang.size()) dfs(mang[i] , 0) ;
 
   cout << depth+1;
}
