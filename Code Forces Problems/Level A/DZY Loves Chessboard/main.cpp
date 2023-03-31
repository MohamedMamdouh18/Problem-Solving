#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int vis[101][101] = {{0}} ;
char board[101][101] ;
int n , m ;
char color[2] = {'B' , 'W'} ;
 
void solve(int i , int j , int col)
{
    if(i > n || j > m|| vis[i][j]) return ;
    vis[i][j] = 1 ;
    if(board[i][j] == '.' )board[i][j] = color[col] ;
    solve(i+1 , j , !col) ;
    solve(i , j+1 , !col) ;
}
 
int main(){
   IOS
   cin >> n >> m ;
   rep(i , 0 , n) rep(j , 0 , m) cin >> board[i][j] ;
 
   solve(0 , 0 , 0) ;
 
   rep(i , 0 , n)
   {
       rep(j , 0 , m) cout << board[i][j] ;
       cout << endl ;
   }
}
