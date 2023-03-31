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
const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;
vector<vector<int>> adj;
vector<bool> visited;
ll cnt;

void dfs(int node) {
    visited[node] = true;
    cnt++;
    for (auto child: adj[node]) {
        if (!visited[child]) dfs(child);
    }
}

ll add(ll x, ll y) {
    return ((((x % mod) + (y % mod)) % mod) + mod) % mod;
}

ll fp(ll base, ll power) {
    if (power == 0) return 1;
    ll res = fp(base, power / 2);
    res = (res * res) % mod;
    if (power & 1) res = (res * base) % mod;
    return res;
}

void GREEN() {
    ll n, k, x, y, c, ans;
    cin >> n >> k;
    ans = fp(n, k);
    adj.clear(), visited.clear();
    adj.resize(n + 1), visited.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y >> c;
        if (!c) {
            adj[x].pb(y);
            adj[y].pb(x);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cnt = 0;
            dfs(i);
            ans = add(ans , -fp(cnt , k)) ;
        }
    }
    cout << ans ;
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
