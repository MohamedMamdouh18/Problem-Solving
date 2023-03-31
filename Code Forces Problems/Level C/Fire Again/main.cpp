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
const ll mod = 1e9 + 7, N = 1e5 + 1;
vector<vector<int>> adj;
bool visited[2001][2001];
vector<pair<int, int>> start;
int n, m, k;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> bfs() {
    queue<pair<int, int>> q;
    pair<int, int> end;
    for (int i = 0; i < start.size(); ++i) {
        visited[start[i].fi][start[i].se] = true;
        q.push({start[i].fi, start[i].se});
    }
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        end = current;
        for (int i = 0; i < 4; ++i) {
            int toX = current.fi + dx[i];
            int toy = current.se + dy[i];
            if (toX > 0 && toX <= n && toy > 0 && toy <= m && !visited[toX][toy]) {
                q.push({toX, toy});
                visited[toX][toy] = true;
            }
        }
    }
    return end;
}


void GREEN() {
    cin >> n >> m >> k;
    start.resize(k);
    for (int i = 0; i < k; ++i) cin >> start[i].fi >> start[i].se;
    auto e = bfs();
    cout << e.fi << " " << e.se;
}

int main() {
    PREC
    IOS
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
