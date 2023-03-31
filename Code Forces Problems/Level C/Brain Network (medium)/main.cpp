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
vector<bool> visited;

int bfs(int start , bool mode) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    int further = -1, maxi = INT_MIN;
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        visited[current.fi] = true;
        if (current.se > maxi) {
            maxi = current.se;
            further = current.fi;
        }
        for (auto child: adj[current.fi]) {
            if (!visited[child])q.push({child, current.se + 1});
        }
    }
    return ((mode) ? further : maxi) ;
}

void GREEN() {
    int n, m, x, y;
    cin >> n >> m;
    adj.resize(n + 1), visited.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    auto node = bfs(1 , true);
    visited.assign(n+1 , false) ;
    cout << bfs(node , false) ;
}

int main() {
    PREC
    IOS
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
