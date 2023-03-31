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
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = LONG_LONG_MAX;
int n, m, a, b, c, x, y;
vector<vector<int>> adj;

void bfs(int start, vector<ll> &dist) {
    dist.assign(n + 1, INF);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int child: adj[cur]) {
            if (dist[child] > dist[cur] + 1) {
                dist[child] = dist[cur] + 1;
                q.push(child);
            }

        }
    }

}

void GREEN() {
    cin >> n >> m >> a >> b >> c;
    ll sum = INF;
    vector<ll> prices(m), prefix(m + 1);
    adj.clear(), adj.resize(n + 1);
    for (int i = 0; i < m; ++i) cin >> prices[i];
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll> dist_a, dist_b, dist_c;
    bfs(a, dist_a);
    bfs(b, dist_b);
    bfs(c, dist_c);
    sort(all(prices));
    for (int i = 0; i < m; ++i) prefix[i + 1] = prefix[i] + prices[i];
    for (int i = 1; i <= n; ++i) {
        if (dist_b[i] < INF && dist_a[i] < INF && dist_c[i] < INF && dist_a[i] + dist_b[i] + dist_c[i] < m + 1)
            sum = min(sum, prefix[dist_b[i]] + prefix[dist_a[i] + dist_b[i] + dist_c[i]]);
    }
    cout << sum << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
