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
const ll mod = 1e9 + 7, N = 2050, M = 2, INF = LONG_LONG_MAX;
const double eps = 1e-6;
int dp[N][N], n, k;

int recursive(int idx, int start) {
    if (idx == k) return 1;
    if (~dp[idx][start]) return dp[idx][start];
    ll ans = 0;
    for (int i = start; i <= n; i += start) {
        ans += recursive(idx + 1, i);
        ans %= mod;
    }
    return dp[idx][start] = ans;

}

void GREEN() {
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << recursive(0, 1);
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
