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
vector<int> dist;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s , int e){
    priority_queue<pair<int , int>> q;
    q.push({0 , s}) ;
    dist[s] = 0 ;
    while (!q.empty()){
        int cost= - q.top().fi , from = q.top().se ;
        q.pop() ;
        if(cost > dist[from]) continue;
        for(auto child : adj[from]){
            int to = child.fi ;
            int new_route = child.se + cost ;
            if(dist[to] > new_route){
                dist[to] = new_route ;
                q.push({-new_route , to}) ;
            }
        }
    }
}

void GREEN() {
    int n, m, s, e, x, y, w;
    cin >> n >> m >> s >> e;
    adj.resize(n + 1), dist.assign(n + 1, 1e9);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
    dijkstra(s,e) ;
    cout << ((dist[e] == 1e9) ? "NONE" : to_string(dist[e])) << el ;
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
