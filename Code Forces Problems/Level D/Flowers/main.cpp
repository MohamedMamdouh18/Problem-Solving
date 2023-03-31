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
const ll mod = 1e9 + 7, N = 1e5 + 50, M = 2, INF = LONG_LONG_MAX;
const double eps = 1e-6;
bool visited[N];
ll dp[N], n, k, d, prefix[N];

int recursive(int rem) {
    if (rem == 0) return 1;
    if (visited[rem]) return dp[rem];
    visited[rem] = true;
    ll ans = recursive(rem - 1);
    ans %= mod;
    if (rem >= k) ans += recursive(rem - k);
    ans %= mod;
    return dp[rem] = ans;
}

void GREEN() {
    int a, b;
    cin >> n >> k;
    for (int i = 1; i < N; ++i) {
        prefix[i] += prefix[i - 1] + recursive(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        cout << (((prefix[b] - prefix[a - 1]) + mod) % mod) << el;
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
