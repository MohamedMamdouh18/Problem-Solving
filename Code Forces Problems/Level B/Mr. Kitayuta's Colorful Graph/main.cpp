#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
vector<vector<vector<int>>> adj;
vector<bool> visited;

bool dfs(int node, int target, int color) {
    if (node == target) return true;
    visited[node] = true;
    bool flag = false;
    for (int i = 0; i < adj[node][color].size(); ++i) {
        int child = adj[node][color][i];
        if (!visited[child]) flag |= dfs(child, target, color);
    }
    return flag;
}

void GO() {
    int n, m, q;
    cin >> n >> m;
    visited.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; ++i) adj[i].resize(m);
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--, c--;
        adj[x][c].pb(y);
        adj[y][c].pb(x);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y, ans = 0;
        cin >> x >> y;
        x--, y--;
        for (int j = 0; j < m; ++j) {
            visited.assign(n, false);
            ans += dfs(x, y, j);
        }
        cout << ans << el;
    }
}

int main() {
    IOS
    PREC

    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
