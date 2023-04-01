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

int n, lvl[N];
vector<vector<pair<int, int>>> adj, ancestor;

void dfs(int node, int par, int cost) {
    lvl[node] = lvl[par] + 1;
    ancestor[node][0].fi = par;
    ancestor[node][0].se = cost;
    for (int j = 1; j < M; j++) {
        int p = ancestor[node][j - 1].fi;
        ancestor[node][j].fi = ancestor[p][j - 1].fi;
        ancestor[node][j].se = max(ancestor[p][j - 1].se, ancestor[node][j - 1].se);
    }
    for (auto child: adj[node]) {
        if (child.fi != par)
            dfs(child.fi, node, child.se);
    }
}

pair<int, int> findKthAncestor(int u, int k) {
    if (k == 0)
        return {u, 0};
    int ans = u, maxi = -1;
    for (int j = M - 1; j >= 0; j--)
        if (k & (1 << j)) {
            maxi = max(maxi, ancestor[ans][j].se);
            ans = ancestor[ans][j].fi;
        }
    return {ans, maxi};
}


pair<int, int> getLCA(int u, int v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    auto ans = findKthAncestor(u, lvl[u] - lvl[v]);
    int maxi = ans.se;
    pair<int, int> temp = {v, 0};
    if (ans.fi == v)
        return ans;
    for (int i = M - 1; i >= 0; i--) {
        if (ancestor[ans.fi][i].fi == ancestor[temp.fi][i].fi)
            continue;
        ans = ancestor[ans.fi][i];
        temp = ancestor[temp.fi][i];
        maxi = max({maxi, ans.se, temp.se});
    }
    return {ancestor[ans.fi][0].fi, max({maxi, ancestor[ans.fi][0].se, ancestor[temp.fi][0].se})};
}

void GREEN() {
    while (cin >> n && n) {
        adj.clear(), ancestor.clear();
        adj.resize(n + 1), ancestor.assign(n + 1, vector<pair<int, int>>(M, {0, 0}));
        memset(lvl, 0, sizeof lvl);
        for (int i = 0; i < n - 1; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].eb(b, c);
            adj[b].eb(a, c);
        }
        dfs(1, 1, 0);
        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            int meet = getLCA(u, v).fi;
            cout << max(getLCA(u, meet).se, getLCA(v, meet).se) << el;
        }
        cout << el;
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
