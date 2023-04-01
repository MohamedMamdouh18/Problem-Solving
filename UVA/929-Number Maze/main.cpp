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
int dist[1000][1000] , grid[1000][1000] ;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
int n ,m ;

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({-grid[0][0], {0, 0}});
    dist[0][0] = grid[0][0];
    while (!q.empty()) {
        int cost = -q.top().fi;
        int a = q.top().se.fi;
        int b = q.top().se.se;
        q.pop();
        if (cost > dist[a][b]) continue;
        for (int i = 0; i < 4; ++i) {
            int c = a + dx[i];
            int d = b + dy[i];
            int new_cost = grid[c][d] + cost;
            if (c >= 0 && d >= 0 && c < n && d < m && dist[c][d] > new_cost) {
                dist[c][d] = new_cost;
                q.push({-new_cost, {c, d}});
            }
        }
    }
}

void GREEN() {
    cin >> n>> m ;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist[i][j] = INT_MAX ;
            cin >> grid[i][j] ;
        }
    }
    dijkstra() ;
    cout << dist[n-1][m-1] << el ;
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
