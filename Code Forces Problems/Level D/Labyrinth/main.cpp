#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e6 + 1;
int n, m, l, r, ans = 1;
char grid[2000][2000];
bool visited[2000][2000];
 
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
 
struct edge {
    int y, x, r_cost, l_cost;
};
 
void bfs(pair<int,int> start) {
    deque<edge> q;
    q.push_front({start.fi, start.se, 0, 0});
    visited[start.fi][start.se] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            int new_x = cur.x + dx[i];
            int new_y = cur.y + dy[i];
            if (dx[i] == 0 && new_y >= 0 && new_y < n && !visited[new_y][new_x] && grid[new_y][new_x] != '*') {
                visited[new_y][new_x] = true;
                ans++;
                q.push_front({new_y, new_x, cur.r_cost, cur.l_cost});
            } else {
                if (dx[i] == 1 && new_x >= 0 && new_x < m && !visited[new_y][new_x] && cur.r_cost + 1 <= r &&
                    grid[new_y][new_x] != '*') {
                    visited[new_y][new_x] = true;
                    ans++;
                    q.push_back({new_y, new_x, cur.r_cost + 1, cur.l_cost});
                } else if (dx[i] == -1 && new_x >= 0 && new_x < m && !visited[new_y][new_x] && cur.l_cost + 1 <= l &&
                           grid[new_y][new_x] != '*') {
                    visited[new_y][new_x] = true;
                    ans++;
                    q.push_back({new_y, new_x, cur.r_cost, cur.l_cost + 1});
                }
            }
        }
    }
}
 
void GREEN() {
    int x , y;
    cin >> n >> m >> y>> x>>l >> r;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    bfs({y-1,x-1});
    cout << ans;
}
 
int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
