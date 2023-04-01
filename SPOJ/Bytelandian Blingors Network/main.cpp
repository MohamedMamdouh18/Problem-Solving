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
int par[N], siz[N];
bool cycle = false;

void init(int n) {
    for (int i = 0; i <= n; ++i) {
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
    int v_par = find_parent(v);
    int u_par = find_parent(u);
    if (v_par == u_par) {
        cycle = true;
        return;
    }
    if (siz[v_par] < siz[u_par]) swap(v_par, u_par);
    par[u_par] = par[v_par];
    siz[v_par] += siz[u_par];
}

void GREEN() {
    ll n, k, x, w, cost = 0, m = 0;
    cin >> n;
    init(n);
    vector<pair<int, pair<int, int>>> road;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s >> k;
        for (int j = 0; j < k; ++j) {
            cin >> x >> w;
            road.pb({w, {i, x}});
        }
    }
    sort(all(road));
    for (int i = 0; i < road.size(); ++i) {
        int u = road[i].se.fi, v = road[i].se.se;
        ll rc = road[i].fi;
        if (is_connected(u, v)) continue;
        connect(u, v);
        cost += rc, m++;
        if (m == n - 1) break;
    }
    cout << cost << el;

}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
