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
    for (auto ch: adj[node]) {
        if (ch == par)
            continue;
        dfs(ch, node);
    }
}

int findKthAncestor(int u, int k) {
    for (int j = M - 1; j >= 0; j--)
        if (k & (1 << j))
            u = ancestor[u][j];
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
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int child;
            cin >> child;
            adj[i].pb(child);
        }
    }
    dfs(0, 0);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << getLCA(u, v) << el;
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
