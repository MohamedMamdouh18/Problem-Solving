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
ll maxi, num;
vector<ll> dist;
vector<pair<ll, ll>> query;
vector<vector<pair<int, ll>>> adj;

void dijkstra(int s) {
    priority_queue<pair<ll, int>> q;
    q.push({0, s});
    dist[s] = 0;
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
    int n, m, q, x, y, w;
    cin >> n >> m >> q;
    adj.resize(n), query.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
    for (int i = 0; i < q; ++i) {
        cin >> x;
        if (query[x].fi != 0 && query[x].se != 0) maxi = query[x].fi, num = query[x].se;
        else {
            dist.assign(n, LONG_LONG_MAX);
            maxi = 0, num = 1;
            dijkstra(x);
            for (int j = 0; j < n; ++j) {
                if(dist[j] == LONG_LONG_MAX || x == j) continue;
                if(dist[j] == maxi) num ++ ;
                if(dist[j] > maxi) maxi = dist[j] , num = 1;
            }
            query[x].fi = maxi, query[x].se = num;
        }
        cout << maxi << " " << num << el;
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
