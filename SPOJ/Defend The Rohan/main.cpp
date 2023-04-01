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
int n, s = 0;
ll dist[51][51];

void FloyedWarshell() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void GREEN() {
    for (int i = 0; i < 51; ++i) {
        for (int j = 0; j < 51; ++j) if (i != j)dist[i][j] = INF;
    }
    ll x, y, m, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            dist[i][j] = x;
        }
    }
    FloyedWarshell();
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        ans += dist[x-1][y-1];
    }
    cout << "Case #" << s << ": " << ans << el;
}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        s++;
        GREEN();
    }
}
