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
vector<vector<pair<int, int>>> adj;
vector<int> deg;
vector<bool> vis_road;
int cnt = 0 ;

void dfs(int node) {
    while (!adj[node].empty()) {
        int u = adj[node].back().fi;
        int indx = adj[node].back().se;
        adj[node].pop_back();
        if (vis_road[indx]) continue;
        vis_road[indx] = true;
        dfs(u);
    }
    cnt ++ ;
}

void GREEN() {
    int n, m, x, y;
    while (cin >> n >> m) {
        cnt = 0 ;
        adj.clear(), deg.clear(), vis_road.clear();
        adj.resize(n), deg.resize(n), vis_road.resize(m);
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            adj[x].pb({y, i});
            adj[y].pb({x, i});
            deg[y]++, deg[x]++;
        }
        if(!m){
            cout << "Not Possible" << el;
            continue;
        }
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if(deg[i] & 1){
                valid = false ;
                break;
            }
        }
        dfs(1);
        if(cnt != m+1) valid = false ;
        cout << ((valid) ? "Possible" : "Not Possible") << el;
    }

}

int main() {
//    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
