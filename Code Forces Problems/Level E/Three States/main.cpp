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
int n, m, best = INT_MAX;
char grid[1000][1000];
int cost[3][1000][1000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct node {
    int row, col, cost;

    node(int row, int col, int cost) : row(row), col(col), cost(cost) {}
};

void bfs(pair<int, int> start, int mode) {
    vector<pair<int, int>> path;
    deque<node> q;
    node s = node(start.fi, start.se, 0);
    q.push_front(s);
    cost[mode][start.fi][start.se] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            int new_row = cur.row + dx[i];
            int new_col = cur.col + dy[i];
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                node new_node = node(new_row, new_col, cur.cost);
                if (grid[new_row][new_col] == '.' && cost[mode][new_row][new_col] > cur.cost + 1) {
                    int new_cost = cur.cost + 1;
                    cost[mode][new_row][new_col] = new_cost;
                    new_node.cost = new_cost;
                    q.push_back(new_node);
                } else if (grid[new_row][new_col] != '.' && grid[new_row][new_col] != '#' &&
                           cost[mode][new_row][new_col] > cur.cost) {
                    cost[mode][new_row][new_col] = cur.cost;
                    q.push_front(new_node);
                }
            }
        }
    }
}

void GREEN() {
    pair<int, int> start1, start2, start3;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '1') start1 = {i, j};
            else if (grid[i][j] == '2') start2 = {i, j};
            else if (grid[i][j] == '3') start3 = {i, j};
            cost[0][i][j] = INT_MAX;
            cost[1][i][j] = INT_MAX;
            cost[2][i][j] = INT_MAX;
        }
    }
    bfs(start1, 0);
    bfs(start2, 1);
    bfs(start3, 2);
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (cost[0][i][j] != INT_MAX && cost[1][i][j] != INT_MAX && cost[2][i][j] != INT_MAX) {
                int c = cost[0][i][j] + cost[1][i][j] + cost[2][i][j] - 2 * (grid[i][j] == '.');
                ans = min(ans, c);
            }
        }
    }

    cout << ((ans == INT_MAX) ? -1 : ans);
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
