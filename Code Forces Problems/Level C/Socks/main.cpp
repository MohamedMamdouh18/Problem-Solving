#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 21, M = 2500, INF = 1e-18;
vector<vector<int>> adj_list;
vector<bool> vis;
map<int, int> color;
map<int, int> freq;
int nodes = 0, maxi = -1;

void dfs(int cur) {
    vis[cur] = true;
    nodes++;
    freq[color[cur]]++;
    maxi = max(maxi, freq[color[cur]]);
    for (int i = 0; i < adj_list[cur].size(); ++i) {
        int next = adj_list[cur][i];
        if (!vis[next])
            dfs(next);
    }
}

void LIGHT_BLUE() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    adj_list.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        color[i + 1] = x;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj_list[x].pb(y);
        adj_list[y].pb(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            ans += (nodes - maxi);
            nodes = 0, maxi = -1;
            freq.clear();
        }
    }
    cout << ans;
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        LIGHT_BLUE();
    }
}
