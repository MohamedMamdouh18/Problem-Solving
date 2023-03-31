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
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = LONG_LONG_MAX;
const double eps = 1e-6;
int n, m, k;
char grid[1000][1000];
int ans[1000][1000];
bool visited[1000][1000];
pair<int, int> parent[1000][1000];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int i, int j) {
    int count = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    parent[i][j] = {i , j} , visited[i][j] = true ;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int l = 0; l < 4; ++l) {
            int new_i = cur.fi + dx[l];
            int new_j = cur.se + dy[l];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                if (grid[new_i][new_j] == '*') count++;
                else if (!visited[new_i][new_j])q.push({new_i, new_j});
                visited[new_i][new_j] = true;
                parent[new_i][new_j] = {i, j};
            }
        }
    }
    ans[i][j] = count;
}

void GREEN() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            parent[i][j] = {-1, -1};
        }
    }
    int x, y;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        x--, y--;
        if (parent[x][y].fi == -1) bfs(x, y);
        cout << ans[parent[x][y].fi][parent[x][y].se] << el;
    }
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
