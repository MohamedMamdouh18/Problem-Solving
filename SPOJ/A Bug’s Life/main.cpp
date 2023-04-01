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
int no = 0;
vector<vector<int>> adj;
vector<bool> visited;
set<int> g1, g2;

bool dfs(int bug, int group) {
    if ((group == 1 && g2.count(bug)) || (group == 2 && g1.count(bug))) return false;
    if (visited[bug]) return true;
    visited[bug] = true;
    if (group == 1) g1.insert(bug);
    else g2.insert(bug);
    bool flag = true;
    for (int i = 0; i < adj[bug].size(); ++i) {
        int child = adj[bug][i];
        flag &= dfs(child, 3 - group);
        if (!flag) return flag;
    }
    return flag;
}

void GREEN() {
    int n, m, x, y;
    cin >> n >> m;
    adj.clear(),visited.clear();
    g1.clear(), g2.clear();
    adj.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) flag &= dfs(i, 1);
    }
    cout << "Scenario #" << no << ":" << el;
    cout << ((!flag) ? "Suspicious bugs found!" : "No suspicious bugs found!") << el;
}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        no++;
        GREEN();
    }
}
