
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
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = INT_MAX;
vector<pair<int, pair<int, int>>> edges;
int mini, indx , n;
vector<int> dist;

bool BellmanFord(int src) {
    dist.assign(n + 1, INF);
    bool negCycle = false;
    dist[src] = 0;
    // O(n * m)
    for (int i = 1; i <= n; i++) {
        bool any = false;
        for (auto edge : edges) {
            int u = edge.se.fi, v = edge.se.se, w = edge.fi;
            if (dist[u] < INF)
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    any = true;
                    if (i == n) negCycle = true;
                }
        }
        if (!any) break;
    }
    return negCycle;
}

void GREEN() {
    int m ;
    cin >> n >> m ;
    edges.resize(m) ;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].se.fi >> edges[i].se.se >> edges[i].fi ;
        edges[i].se.fi ++ , edges[i].se.se ++ ;
    }
    if(BellmanFord(1)) cout << "possible" << el ;
    else cout << "not possible" << el ;


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
