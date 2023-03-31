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
ll par[N], siz[N];

void init() {
    for (int i = 0; i < N; ++i) {
        par[i] = i;
        siz[i] = 1;
    }
}

int find_parent(int x) {
    if (x == par[x]) return x;
    return par[x] = find_parent(par[x]);
}

bool is_connected(int u, int v) {
    return find_parent(u) == find_parent(v);
}

void connect(int u, int v) {
    int par_u = find_parent(u);
    int par_v = find_parent(v);
    if (par_u == par_v) return;

    if (siz[par_v] > siz[par_u]) swap(par_v, par_u);
    par[par_v] = par_u;
    siz[par_u] += siz[par_v];
}

void GREEN() {
    ll n, m, x, y, w, mini = LONG_LONG_MAX, ind;
    ll ans = 0;
    cin >> n >> m;
    init();
    vector<pair<ll, pair<ll, ll>>> edge;
    vector<ll> cost(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
        if (cost[i] < mini) {
            mini = cost[i];
            ind = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i == ind) continue;
        edge.pb({mini + cost[i], {ind, i}});
    }
    for (int i = 0; i < m; ++i) {
        cin >> x>> y>> w;
        edge.pb({w, {x, y}});
    }
    sort(all(edge)) ;
    for (int i = 0; i < edge.size(); ++i) {
        ll u = edge[i].se.fi , v = edge[i].se.se ;
        ll c = edge[i].fi ;
        if(is_connected(u , v)) continue;

        ans += c ;
        connect(u , v) ;
    }

    cout << ans;
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
