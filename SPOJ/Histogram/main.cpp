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
const ll mod = 1e9 + 7, N = 1e5, M = 20, INF = LONG_LONG_MAX;
const double eps = 1e-6;
int n;
pair<int, int> dp[N][M];
vector<int> height(M);

pair<int, int> solve(int msk, int idx) {
    if (msk == ((1 << n) - 1)) {
        return {height[idx], 1};
    }
    if (~dp[msk][idx].fi) return dp[msk][idx];
    pair<int, int> ret = {0, 0};
    for (int i = 1; i <= n; ++i) {
        if (msk & (1 << (i - 1))) continue;
        auto temp = solve(msk | (1 << (i - 1)), i);
        temp.fi +=  abs(height[i] - height[idx]);
        if (temp.fi == ret.fi) ret.se += temp.se;
        else ret = max(ret, temp);
    }
    return dp[msk][idx] = ret;
}

void GREEN() {
    height[0] = 0;
    while (cin >> n && n) {
        for (int i = 1; i <= n; ++i) {
            cin >> height[i];
        }
        memset(dp, -1, sizeof dp);
        auto ans = solve(0, 0);
        cout << ans.fi + 2 * n<< " " << ans.se << el;
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
