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
int current;

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); ++i) {
        int child = adj[node][i];
        if (!visited[child]) current++, dfs(child);
    }
}

void GREEN() {
    int n, m, x , y;
    cin >> n >> m;
    adj.clear() ;
    visited.clear();
    adj.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        current = 1;
        if (!visited[i])dfs(i);
        ans = max(ans, current);
    }
    cout << ans << el;
}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
