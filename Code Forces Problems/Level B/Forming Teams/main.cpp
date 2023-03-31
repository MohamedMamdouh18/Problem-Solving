#include <bits/stdc++.h>
#include <math.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int vis[101] ;
vector<vector<int>> adj_list(101) ;
int n , cnt = 0;

bool dfs(int node , int par)
{
    if(vis[node]) return true ;
    vis[node] = 1 ;

    for(auto child: adj_list[node])
    {
        if(child != par)
        {
            cnt ++ ;
            if(dfs(child , node)) return true ;
        }

    }
    return false ;
}

int main(){
   IOS
   int  m , x , y , toremove = 0;
   cin >> n >> m ;

   while(m --)
   {
       cin >>x >> y;
       x -- , y -- ;
       adj_list[x].pb(y) ;
       adj_list[y].pb(x) ;
   }
   rep(i , 0 , n)
   {
       if(!vis[i])
       {
            cnt = 0 ;
           if(dfs(i , -1))
            if(cnt % 2) toremove ++ ;
            int x = cnt ;
       }
   }
   if( (n - toremove) % 2) toremove ++ ;
   cout<< toremove ;
}
