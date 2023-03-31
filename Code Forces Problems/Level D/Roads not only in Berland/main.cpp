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
    int v_par = find_parent(v);
    int u_par = find_parent(u);
    if (v_par == u_par) return;
    if (siz[v_par] < siz[u_par]) swap(v_par, u_par);
    par[u_par] = par[v_par];
    siz[v_par] += siz[u_par];
}

void GREEN() {
    int n, x, y;
    cin >> n ;
    vector<pair<int, int>> close, build;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        if (is_connected(x, y)) close.eb(x, y);
        else connect(x, y);
    }
    for (int i = 2; i <= n; ++i) {
        if (!is_connected(1, i)) {
            connect(1, i);
            build.eb(1, i);
        }
    }
    cout << min(close.size(), build.size()) << el;
    for (int i = 0; i < min(close.size(), build.size()); ++i) {
        cout << close[i].fi << " " << close[i].se << " " << build[i].fi << " " << build[i].se << el;
    }
}

int main() {
    PREC
    IOS
    init();
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
