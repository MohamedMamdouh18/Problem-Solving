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
const ll mod = 1e9 + 7, N = 1e5 + 1;
vector<vector<int>> adj;
vector<int> ans;
vector<bool> visited;
map<pair<int, int>, bool> problem;

bool dfs(int node, int parent){
    visited[node] = true ;
    bool covered = false ;
    for(auto child : adj[node]){
        if(!visited[child]){
            covered |= dfs(child , node) ;
        }
    }
    if(!covered){
        if(problem[{node,parent}]) {
            ans.pb(node) ;
            return true ;
        }else return false ;
    }else return true ;
}

void GREEN() {
    int n, x, y, p;
    cin >> n;
    visited.resize(n + 1), adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y >> p;
        adj[x].pb(y);
        adj[y].pb(x);
        p--;
        if (p) {
            problem[{x, y}] = true;
            problem[{y, x}] = true;
        }
    }
    dfs(1 , -1) ;
    cout << ans.size() << el ;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " " ;
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
