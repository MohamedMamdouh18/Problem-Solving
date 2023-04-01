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
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int child : adj[node]) {
        if (!visited[child])dfs(child);
    }
}

void solve() {
    int n, m, cnt = 0;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    if (m != n - 1) {
        cout << "NO";
        return;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << ((cnt > 1) ? "NO" : "YES");

}

int main() {
    IOS
    PREC

    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
