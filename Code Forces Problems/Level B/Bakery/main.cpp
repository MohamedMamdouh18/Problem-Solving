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
vector<vector<pair<ll, ll>>> adj;
vector<bool> visited;
vector<bool> storage;
ll cost = LONG_LONG_MAX;

void dfs(int node) {
    visited[node] = true ;
    for (int i = 0; i < adj[node].size(); ++i) {
        ll child = adj[node][i].fi ;
        ll roadCost = adj[node][i].se ;
        if(!storage[node] && storage[child]) cost = min(cost , roadCost) ;
        if(!visited[child]) dfs(child) ;
    }
}

void GO() {
    ll n, m, k, x, y, c;
    cin >> n >> m >> k;
    visited.resize(n);
    adj.resize(n);
    storage.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> c;
        x--, y--;
        adj[x].emplace_back(y, c);
        adj[y].emplace_back(x, c);
    }
    for (int i = 0; i < k; ++i) {
        cin >> x;
        x--;
        storage[x] = true;
    }
    for (int i = 0; i < n; ++i) if (!visited[i]) dfs(i);
    cout << ((cost == LONG_LONG_MAX) ? -1 : cost) ;

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
