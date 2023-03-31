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
const double eps = 1e-6;
ll n, m;


void dijkstra(ll start, vector<ll> &dist, vector<vector<pair<ll, ll>>> &adj) {
    dist.assign(n + 1, INF);
    dist[start] = 0;
    priority_queue<pair<ll, ll>> q;
    q.push({0, start});
    while (!q.empty()) {
        ll from = q.top().se, cost = -q.top().fi;
        q.pop();
        for (auto child: adj[from]) {
            ll to = child.fi;
            ll new_route = cost + child.se;
            if (new_route < dist[to]) {
                dist[to] = new_route;
                q.push({-new_route, to});
            }
        }
    }
}

void GREEN() {
    ll x, y, l, s, e;
    cin >> n >> m;
    cin >> s >> e;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<pair<ll, ll>> taxi(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> l;
        adj[x].pb({y, l});
        adj[y].pb({x, l});
    }
    for (int i = 1; i <= n; ++i) {
        cin >> taxi[i].fi >> taxi[i].se;
    }
    vector<vector<ll>> dist(n + 1);
    for (int i = 1; i <= n; ++i) dijkstra(i, dist[i], adj);
    vector<vector<pair<ll, ll>>> roads(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (taxi[i].fi >= dist[i][j])
                roads[i].pb({j, taxi[i].se});
        }
    }
    vector<ll> costs;
    dijkstra(s, costs, roads);
    cout << ((costs[e] == INF) ? -1 : costs[e]);

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
