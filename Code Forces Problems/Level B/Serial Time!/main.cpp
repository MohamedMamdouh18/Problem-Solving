#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int k , m , n , flr = 0 , ans = 0 , xs , ys;
char plate[10][10][10] ;
int vis[10][10][10] = {{{0}}};
 
void dfs(int flr ,int x , int y)
{
    vis[flr][x][y] = 1 ;
    ans ++ ;
    if(flr-1 >= 0 && !vis[flr-1][x][y] && plate[flr-1][x][y] == '.') dfs(flr-1 , x , y) ;
    if(flr+1 < k && !vis[flr+1][x][y] && plate[flr+1][x][y] == '.') dfs(flr+1 , x , y) ;
    if(x-1 >= 0 && !vis[flr][x-1][y] && plate[flr][x-1][y] == '.') dfs(flr , x-1 , y) ;
    if(x+1 < n && !vis[flr][x+1][y] && plate[flr][x+1][y] == '.') dfs(flr , x+1 , y) ;
    if(y-1 >= 0 && !vis[flr][x][y-1] && plate[flr][x][y-1] == '.') dfs(flr , x , y-1) ;
    if(y+1 < m && !vis[flr][x][y+1] && plate[flr][x][y+1] == '.') dfs(flr , x , y+1) ;
}
 
int main(){
   IOS
   cin >> k >> n >> m ;
   rep(i , 0 , k)
   {
       rep(j , 0 , n)
       {
           rep(l , 0 , m) cin >> plate[i][j][l] ;
       }
   }
 
   cin >> xs >> ys ;
   xs -- ; ys -- ;
 
   dfs(0 , xs , ys) ;
 
   cout << ans ;
}
