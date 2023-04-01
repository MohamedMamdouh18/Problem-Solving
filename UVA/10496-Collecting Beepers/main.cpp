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
const ll mod = 1e9 + 7, N = 1e4, M = 20, INF = LONG_LONG_MAX;
const double eps = 1e-6;
ll dp[N][M];
int n, m, k;

vector<pair<int, int>> beeper(M);

ll solve(ll msk, ll last) {
    if (msk == ((1 << (k + 1)) - 1)) {
        return abs(beeper[last].fi - beeper[0].fi) +
               abs(beeper[last].se - beeper[0].se);
    }
    if (~dp[msk][last]) return dp[msk][last];
    ll ans = LONG_LONG_MAX;
    for (int i = 1; i <= k; ++i) {
        if (msk & (1 << i)) continue;
        ans = min(ans, solve(msk | (1 << i), i) +
                       abs(beeper[last].fi - beeper[i].fi) + abs(beeper[last].se - beeper[i].se));
    }
    return dp[msk][last] = ans;
}

void GREEN() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> beeper[0].fi >> beeper[0].se >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> beeper[i].fi >> beeper[i].se;
    }
    cout << "The shortest path has length " << solve(1, 0) << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
