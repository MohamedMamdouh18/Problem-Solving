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
const ll mod = 1e9 + 7, N = 1e6 + 1;
vector<ll> dist, price;
vector<vector<pair<int, ll>>> adj;

void dijkstra() {
    priority_queue<pair<ll, int>> q;
    for (int i = 1; i < price.size(); ++i) {
        q.push({-price[i], i});
        dist[i] = price[i];
    }
    while (!q.empty()) {
        ll cost = -q.top().fi;
        int from = q.top().se;
        q.pop();
        if (cost > dist[from]) continue;
        for (auto child: adj[from]) {
            int to = child.fi;
            ll new_route = child.se + cost;
            if (dist[to] > new_route) {
                dist[to] = new_route;
                q.push({-new_route, to});
            }
        }
    }
}

void GREEN() {
    ll n, m, x, y, w;
    cin >> n >> m;
    adj.resize(n + 1), dist.assign(n + 1, LONG_LONG_MAX), price.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> w;
        adj[x].pb({y, w * 2});
        adj[y].pb({x, w * 2});
    }
    for (int i = 1; i < price.size(); ++i) cin >> price[i];

    dijkstra();
    for (int i = 1; i < dist.size(); ++i) {
        cout << dist[i] << " ";
    }

}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
