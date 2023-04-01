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

const ll mod = 1e9 + 7, N = 8000, M = 2, INF = LONG_LONG_MAX;
const double eps = 1e-6;
ll dp[N][5];
int coins[] = {1, 5, 10, 25, 50};

ll solve(ll rem, int idx) {
    if (idx == 0 || rem == 0) return 1;
    if (~dp[rem][idx]) return dp[rem][idx];
    ll op1 = 0, op2 = 0;
    if (rem >= coins[idx]) op1 = solve(rem - coins[idx], idx);
    op2 = solve(rem, idx - 1);
    return dp[rem][idx] = op1 + op2;
}

void GREEN() {
    ll n;
    memset(dp , -1 , sizeof dp) ;
    while (cin >> n) {
        cout << solve(n, 4) << el;
    }
}

int main() {
//    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
