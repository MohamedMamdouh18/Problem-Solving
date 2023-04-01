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
const int mod = 1e9 + 7, N = 2e5 + 50, M = 20, INF = INT_MAX;
const double eps = 1e-6;

int n, ancestor[N][M], lvl[N];
vector<vector<int>> adj;

void dfs(int node, int par) {
    lvl[node] = lvl[par] + 1;

    ancestor[node][0] = par;
    for (int j = 1; j < M; j++) {
        int p = ancestor[node][j - 1];
        ancestor[node][j] = ancestor[p][j - 1];
    }
    for (auto child: adj[node]) {
        if (child != par)
            dfs(child, node);
    }
}

int findKthAncestor(int u, int k) {
    for (int j = M - 1; j >= 0; j--)
        if (k & (1 << j)) {
            u = ancestor[u][j];
        }
    return u;
}

int getLCA(int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    u = findKthAncestor(u, lvl[u] - lvl[v]);
    if (u == v)
        return u;
    for (int i = M - 1; i >= 0; i--) {
        if (ancestor[u][i] == ancestor[v][i])
            continue;
        u = ancestor[u][i];
        v = ancestor[v][i];
    }
    return ancestor[u][0];
}

void GREEN() {
    while (cin >> n && n) {
        adj.clear();
        adj.resize(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1, 1);
        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            int meet = getLCA(u, v);
            int dist = abs(lvl[meet] - lvl[u]) + abs(lvl[meet] - lvl[v]);
            int depth = dist / 2;
            if (dist & 1) {
                int first = findKthAncestor(((lvl[v] < lvl[u]) ? u : v), depth);
                int second = ancestor[first][0];
                cout << "The fleas jump forever between " << min(first, second) << " and " << max(first, second) << "."
                     << el;
            } else {
                cout << "The fleas meet at " << findKthAncestor(((depth <= lvl[u] - lvl[meet]) ? u : v), depth) << "."
                     << el;
            }
        }
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
