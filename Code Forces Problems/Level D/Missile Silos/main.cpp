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
vector<vector<pair<ll, ll>>> adj;
vector<pair<pair<ll, ll>, ll>> edges;
vector<ll> dist;
ll n, m, s;

void dijkstra(ll src) {
    dist[src] = 0;
    priority_queue<pair<ll, ll>> q;
    q.push({-dist[src], src});
    while (!q.empty()) {
        ll from = q.top().se, cost = -q.top().fi;
        q.pop();
        if (cost > dist[from]) continue;
        for (auto child: adj[from]) {
            ll to = child.fi, new_cost = cost + child.se;
            if (new_cost < dist[to]) {
                dist[to] = new_cost;
                q.push({-new_cost, to});
            }
        }
    }
}

void GREEN() {
    ll x, y, w, l, ans = 0;
    cin >> n >> m >> s;
    adj.resize(n + 1), dist.assign(n + 1, INF);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
        edges.pb({{x, y}, w});
    }
    cin >> l;
    dijkstra(s);
    for (int i = 1; i <= n; ++i) {
        ans += (dist[i] == l);
    }
    for (auto edge: edges) {
        ll u = edge.fi.fi, v = edge.fi.se, cost = edge.se;
        ll rem = l - dist[u];
        if (rem > 0 && rem < cost) {
            ll other_vertex = dist[v] + (cost - rem);
            if (other_vertex > l) ans++;
        }
        rem = l - dist[v];
        if (rem > 0 && rem < cost) {
            ll other_vertex = dist[u] + (cost - rem);
            if (other_vertex >= l) ans++;
        }
    }
    cout << ans;
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
