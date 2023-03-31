#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int vis[100] ;
vector<vector<int>> adj_list(100) ;
vector<int> to_remove;
ll n , m , flag = 0 , removed = 0;
 
 
void bfs(int node)
{
   queue<int> q ;
   int siz = 0 ;
   q.push(node) ;
   vis[node] = 0 ;
   for(; !q.empty() ; siz = q.size())
   {
       while(siz --)
       {
           int cur = q.front() ; q.pop() ;
           rep(i , 0 , adj_list[cur].size())
           {
               int child = adj_list[cur][i] ;
               if(vis[child] == -1)
               {
                   vis[child] = vis[cur] + 1;
                   q.push(child) ;
               }
 
               if(adj_list[cur].size() == 1) to_remove.pb(cur) ;
           }
       }
   }
}
 
int main(){
   IOS
   int x , y , ans = 0 ;
   cin >> n >> m ;
   rep(i , 0 , m)
   {
       cin >> x >> y ;
       x--,y--;
       adj_list[x].pb(y) ;
       adj_list[y].pb(x) ;
   }
 
   while(!flag)
   {
       memset(vis , -1 , sizeof vis) ;
       rep(i , 0 , n)
       {
          if(vis[i] == -1) bfs(i) ;
       }
       if(to_remove.empty())flag = 1;
       else
       {
           rep(i , 0 , to_remove.size())
           {
               int par = adj_list[to_remove[i]][0] ;
               rep(j , 0 , adj_list[par].size())
               {
                   int child = to_remove[i] ;
                   if(child == adj_list[par][j]) adj_list[par].erase(adj_list[par].begin()+j) ;
               }
               adj_list[to_remove[i]].clear() ;
           }
       }
       to_remove.clear() ;
       ans ++ ;
   }
   cout << ans-1 ;
}
