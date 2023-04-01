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
const ll mod = 1e9 + 7, N = 1e4 + 50, M = 1050, INF = LONG_LONG_MAX;
const double eps = 1e-6;
bool visited[N];
ll dp[N], n, cnt = 0;
ll num[N];

ll recursive(int idx) {
    if (idx >= n) return 0;
    if (visited[idx]) return dp[idx];
    visited[idx] = true ;
    ll op1 = num[idx] + recursive(idx + 2),
            op2 = recursive(idx + 1);
    return dp[idx] = max(op1, op2);

}

void GREEN() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> num[i];
    memset(visited, false, sizeof(visited));
    cout << "Case " << cnt << ": " << recursive(0) << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        cnt++;
        GREEN();
    }
}
