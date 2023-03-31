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
vector<int> cat ;
int ans = 0 , m;

void dfs(int node, int currentCat) {
    if(visited[node]) return;
    visited[node] = 1 ;
    if(cat[node]) currentCat ++ ;
    else currentCat = 0 ;
    if(currentCat > m) return;
    if(adj[node].size() == 1 && node != 0) ans ++ ;
    for (int i = 0; i < adj[node].size(); ++i){
        int child = adj[node][i];
        dfs(child , currentCat) ;
    }
}

void solve() {
    int n  ;
    cin >> n >> m ;
    adj.resize(n) ;
    visited.resize(n) ;
    cat.resize(n) ;
    for (int i = 0; i < n; ++i) cin >> cat[i] ;
    for (int i = 0; i < n - 1; ++i) {
        int x , y ;
        cin >> x >> y ;
        x -- , y -- ;
        adj[x].pb(y) ;
        adj[y].pb(x) ;
    }
    dfs(0, 0) ;
    cout << ans ;
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
