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
const int mod = 1e9 + 7, N = 2e4 + 50, M = 16, INF = INT_MAX;
const double eps = 1e-6;

int n, m, s, ancestor[N][M], min_weight[N][M], lvl[N], par[N], siz[N];;
vector<vector<pair<int, int>>> adj;
vector<pair<int, pair<int, int>>> edge_list;

void init() {
    for (int i = 0; i < N; ++i) {
        par[i] = i;
        siz[i] = 1;
    }
}

int find_parent(int x) {
    if (par[x] == x) return x;
    return par[x] = find_parent(par[x]);
}

bool is_connected(int u, int v) {
    return find_parent(u) == find_parent(v);
}

void connect(int u, int v) {
    int par_v = find_parent(v);
    int par_u = find_parent(u);
    if (par_v == par_u) return;

    if (siz[par_v] > siz[par_u]) swap(par_u, par_v);
    par[par_v] = par_u;
    siz[par_u] += siz[par_v];
}


void dfs(int node, int par, int cost) {
    lvl[node] = lvl[par] + 1;
    ancestor[node][0] = par;
    min_weight[node][0] = cost;

    for (int j = 1; j < M; j++) {
        if (pow(2, j) >= lvl[node])
            break;
        int p = ancestor[node][j - 1];
        ancestor[node][j] = ancestor[p][j - 1];
        min_weight[node][j] = min(min_weight[node][j - 1], min_weight[p][j - 1]);
    }
    for (auto child: adj[node]) {
        if (child.fi != par)
            dfs(child.fi, node, child.se);
    }
}

pair<int, int> findKthAncestor(int u, int k) {
    pair<int, int> ans = {u, INT_MAX};
    for (int j = M - 1; j >= 0; j--)
        if (k & (1 << j)) {
            ans.se = min(ans.se, min_weight[ans.fi][j]);
            ans.fi = ancestor[ans.fi][j];
        }
    return ans;
}

int getLCA(int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    auto ans = findKthAncestor(u, lvl[u] - lvl[v]);
    u = ans.fi;
    int mini = ans.se;
    if (u == v)
        return mini;
    for (int i = M - 1; i >= 0; i--) {
        if (ancestor[u][i] == ancestor[v][i])
            continue;
        mini = min({mini, min_weight[u][i], min_weight[v][i]});
        u = ancestor[u][i];
        v = ancestor[v][i];
    }
    return min({mini, min_weight[u][0], min_weight[v][0]});
}

void GREEN() {
    while (cin >> n >> m >> s) {
        adj.clear(), edge_list.clear();
        adj.resize(n + 1);
        init();
        memset(lvl, 0, sizeof lvl);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                min_weight[i][j] = INT_MAX;
                ancestor[i][j] = 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            edge_list.pb({c, {a, b}});
        }
        sort(edge_list.rbegin(), edge_list.rend());
        for (auto edge: edge_list) {
            int u = edge.se.fi, v = edge.se.se, cost = edge.fi;
            if (is_connected(u, v))
                continue;
            adj[u].pb({v, cost});
            adj[v].pb({u, cost});
            connect(u, v);
        }
        dfs(1, 1, INT_MAX);
        for (int i = 0; i < s; ++i) {
            int u, v;
            cin >> u >> v;
            cout << getLCA(u, v) << el;
        }
    }
}

int main() {
//    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
