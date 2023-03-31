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
const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;
vector<vector<int>> adj;
vector<int> dep ,edge;

void bfs() {
    queue<int> q;
    for (int i = 1; i < edge.size(); ++i) {
        if(edge[i] == 1) q.push(i) ;
    }
    while (!q.empty()){
        auto cur = q.front() ;
        q.pop() ;
        for(auto child : adj[cur]){
            edge[child] -- ;
            if(edge[child] == 1){
                q.push(child) ;
                dep[child] = dep[cur] + 1;
            }
        }
    }
}

void GREEN() {
    int n , k ,x,y , ans = 0;
    cin >> n >> k ;
    adj.clear(),dep.clear() ,edge.clear();
    adj.resize(n+1) , dep.resize(n+1) ,edge.resize(n+1);
    for (int i = 0; i < n-1; ++i) {
        cin >> x >> y;
        adj[x].pb(y) ;
        adj[y].pb(x) ;
        edge[x] ++  ,edge[y] ++ ;
    }
    bfs() ;
    for (int i = 1; i <= n; ++i) {
        if(dep[i] < k) ans ++ ;
    }
    cout << n - ans << el ;
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
