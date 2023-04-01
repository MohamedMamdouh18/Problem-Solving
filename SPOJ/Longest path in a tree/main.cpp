#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
vector<vector<int>> adj;
vector<bool> visited;
vector<int> depth;

void dfs(int node) {
    visited[node] = true;
    for (int child: adj[node]) {
        if (!visited[child]) {
            depth[child] = depth[node] + 1;
            dfs(child);
        }
    }
}

void solve() {
    int n,max1 = INT_MIN , further;
    cin >> n;
    adj.resize(n + 1);
    visited.resize(n + 1);
    depth.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    depth[1] = 0;
    dfs(1);
    for (int i = 1; i < depth.size(); ++i) {
        if(depth[i] > max1){
            max1 = depth[i] ;
            further = i ;
        }
    }
    depth[further] = 0 ;
    visited.assign(n+1 , 0) ;
    dfs(further) ;
    max1 = INT_MIN ;
    for (int i = 1; i < depth.size(); ++i) max1 = max(max1 , depth[i]) ;
    cout << max1 ;

}

int main() {
    IOS
    PREC

    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
