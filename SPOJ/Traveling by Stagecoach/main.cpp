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
const ll mod = 1e9 + 7, N = 1e4, M = 35, INF = LONG_LONG_MAX;
const double eps = 1e-6;
int n, m, p, a, b;
bool flag = false, vis[N][M];
double dp[N][M];
vector<double> ticket(M);
vector<vector<pair<int, int>>> roads;

double solve(int msk, int cur, int par) {
    if (cur == b) {
        flag = true;
        return 0;
    }
    if (msk == (1 << n) - 1) return 1e7;
    if (vis[msk][cur]) return dp[msk][cur];
    vis[msk][cur] = true;
    double ret = INT_MAX;
    for (auto road: roads[cur]) {
        if (road.fi == par) continue;
        for (int i = 0; i < n; ++i) {
            if (msk & (1 << i)) continue;
            ret = min(ret, solve(msk | (1 << i), road.fi, cur) + (double) road.se / ticket[i]);
        }
    }
    return dp[msk][cur] = ret;
}

void GREEN() {
    while (cin >> n >> m >> p >> a >> b && n) {
        flag = false;
        roads.clear();
        roads.resize(m + 1);
        memset(vis, false, sizeof vis);
        for (int i = 0; i < n; ++i) cin >> ticket[i];
        for (int i = 0; i < p; ++i) {
            int x, y, c;
            cin >> x >> y >> c;
            roads[x].eb(y, c);
            roads[y].eb(x, c);
        }
        solve(0, a, -1);
        if (flag) cout << dp[0][a] << el;
        else cout << "Impossible" << el;
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
