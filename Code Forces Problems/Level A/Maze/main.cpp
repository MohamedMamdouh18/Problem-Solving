#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

char grid[500][500] ;
int vis[500][500] = {{0}} ;
int n , m , k , cnt = 0 , cell = 0;

void dfs(int i , int j) {
    cnt ++ ;
    vis[i][j] = 1 ;
    if(cnt == cell - k) return ;
    if(i+1 < n && !vis[i+1][j] && cnt < cell - k && grid[i+1][j] == '.') dfs(i+1 , j) ;
    if(i-1 >= 0  && !vis[i-1][j] && cnt < cell - k&& grid[i-1][j] == '.') dfs(i-1 , j) ;
    if(j+1 < m && !vis[i][j+1] && cnt < cell - k&& grid[i][j+1] == '.') dfs(i , j+1) ;
    if(j-1 >= 0  && !vis[i][j-1] && cnt < cell - k&& grid[i][j-1] == '.') dfs(i , j-1) ;
}

int main() {
    IOS
    cin >> n >> m >> k ;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j] ;
            if(grid[i][j] == '.') cell ++ ;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == '.')
            {
                dfs(i , j) ;
                i = n ;
                j = m ;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == '.' && !vis[i][j]) grid[i][j] = 'X' ;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j] ;
        }
        cout << endl ;
    }

}
