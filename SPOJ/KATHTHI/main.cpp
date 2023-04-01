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
int n, m;
char grid[1010][1010];
int cost[1010][1010];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
struct edge {
    int y, x, cost;
};

void bfs() {
    deque<edge> q;
    q.push_front({0, 0, 0});
    cost[0][0] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            int new_y = cur.y + dy[i];
            int new_x = cur.x + dx[i];
            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                if (grid[cur.y][cur.x] == grid[new_y][new_x] && cost[new_y][new_x] > cur.cost) {
                    q.push_front({new_y, new_x, cur.cost});
                    cost[new_y][new_x] = cur.cost;
                } else if (grid[cur.y][cur.x] != grid[new_y][new_x] && cost[new_y][new_x] > cur.cost + 1) {
                    q.push_back({new_y, new_x, cur.cost + 1});
                    cost[new_y][new_x] = cur.cost + 1;
                }
            }
        }
    }
}

void GREEN() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            cost[i][j] = INT_MAX;
        }
    }
    bfs();
    int ans =cost[n - 1][m - 1] ;
    cout << ans << el;
}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
