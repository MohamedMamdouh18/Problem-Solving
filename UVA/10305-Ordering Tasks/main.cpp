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
vector<bool> visited;
vector<int> ans;
int current;

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); ++i) {
        int child = adj[node][i];
        if (!visited[child]) dfs(child);
    }
    ans[node] = current++;
}

void GREEN() {
    int n, m;
    while (cin >> n >> m && n) {
        int x, y;
        adj.clear(), visited.clear(), ans.clear();
        adj.resize(n + 1), visited.resize(n + 1), ans.resize(n + 1);
        current = 1;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            adj[y].pb(x);
        }
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) dfs(i);
        }
        for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << el;
    }

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
