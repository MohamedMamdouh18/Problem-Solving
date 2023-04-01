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
int n;
vector<pair<int, pair<int, int>>> edge;
vector<vector<int>> dist;

void BellmanFord(int src , vector<int> &dist) {
    dist.assign(n + 1, INF);
    bool negCycle = false;
    dist[src] = 0;
    // O(n * m)
    for (int i = 1; i <= n; i++) {
        bool any = false;
        for (int j = 0; j < edge.size(); j++) {
            int u = edge[j].se.fi, v = edge[j].se.se, w = edge[j].fi;
            if (dist[u] < INF)
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    any = true;
                    if (i == n) negCycle = true;
                }
        }
        if (!any) break;
    }
}

void GREEN() {
    int x, w,q;
    cin >> n;
    edge.clear() ;
    dist.clear() ;
    dist.resize(n+1) ;
    map<string  , int> city ;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        city[s] = i ;
        int r;
        cin >> r;
        for (int j = 0; j < r; ++j) {
            cin >> x >> w;
            edge.pb({w, {i, x}});
        }
    }
    cin >> q ;
    for (int i = 0; i < q ; ++i) {
        string s1 , s2 ;
        cin >> s1 >> s2 ;
        int a = city[s1] , b = city[s2] ;
        if(dist[a].empty() && dist[b].empty()){
            BellmanFord(a , dist[a]) ;
            cout << dist[a][b] << el ;
        }else if(!dist[a].empty()){
            cout << dist[a][b] << el ;
        }else{
            cout << dist[b][a] ;
        }
    }
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
