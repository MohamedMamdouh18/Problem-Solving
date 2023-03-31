#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

char game[52][52] = {{'0'}} ;
int vis[52][52] = {{0}} ;
int n , m , flag = 0;

void dfs(int i , int j ,char letter)
{
    if((vis[i+1][j] && vis[i][j+1] && game[i+1][j] == letter && game[i][j+1] == letter) ||
       (vis[i+1][j] && vis[i][j-1] && game[i+1][j] == letter && game[i][j-1] == letter) ||
       (vis[i-1][j] && vis[i][j-1] && game[i-1][j] == letter && game[i][j-1] == letter) ||
       (vis[i-1][j] && vis[i][j+1] && game[i-1][j] == letter && game[i][j+1] == letter) ||
       (vis[i-1][j] && vis[i+1][j] && game[i-1][j] == letter && game[i+1][j] == letter) ||
       (vis[i][j-1] && vis[i][j+1] && game[i][j+1] == letter && game[i][j-1] == letter) )
    {
        flag = 1 ;
        return ;
    }
    vis[i][j] = 1 ;

    if(game[i+1][j] == letter && !vis[i+1][j]) dfs(i+1 , j , letter) ;
    if(game[i-1][j] == letter && !vis[i-1][j]) dfs(i-1 , j , letter) ;
    if(game[i][j+1] == letter && !vis[i][j+1]) dfs(i , j+1 , letter) ;
    if(game[i][j-1] == letter && !vis[i][j-1]) dfs(i , j-1 , letter) ;

}


int main(){
   IOS
   cin >> n >> m ;
   rep(i , 1 , n+1)
   {
       rep(j , 1 , m + 1) cin >> game[i][j] ;
   }

   rep(i , 1 , n+1)
   {
       rep(j , 1 , m + 1)
       {
           if(!vis[i][j]) dfs(i , j , game[i][j]) ;
       }
   }

   if(flag) cout << "Yes" ;
   else cout << "No" ;
}
