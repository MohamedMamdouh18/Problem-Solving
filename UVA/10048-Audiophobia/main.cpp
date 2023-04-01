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
int n, t = 0;
ll dist[101][101];

void FloyedWarshell() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
            }
        }
    }
}

void GREEN() {
    int s, q;
    while (cin >> n >> s >> q && n) {
        t++;
        if (t > 1)cout << el;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) dist[i][j] = INF;
                else dist[i][j] = 0;
            }
        }
        ll x, y, w;
        for (int i = 0; i < s; ++i) {
            cin >> x >> y >> w;
            dist[x][y] = min(dist[x][y], w);
            dist[y][x] = min(dist[y][x], w);
        }
        FloyedWarshell();
        cout << "Case #" << t << el;
        for (int i = 0; i < q; ++i) {
            cin >> x >> y;
            if (dist[x][y] == INF) cout << "no path" << el;
            else cout << dist[x][y] << el;
        }
    }
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
