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

struct dsu {
    bool cycle = false;
    int par[1001], siz[1001];

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

};

void GREEN() {
    int n, m1, m2, x, y;
    cin >> n >> m1 >> m2;
    dsu mocha, diana;
    vector<pair<int, int>> ans;
    mocha.init(n), diana.init(n);
    for (int i = 0; i < m1; ++i) {
        cin >> x >> y;
        mocha.connect(x, y);
    }
    for (int i = 0; i < m2; ++i) {
        cin >> x >> y;
        diana.connect(x, y);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (!diana.is_connected(i, j) && !mocha.is_connected(i, j)) {
                ans.pb({i, j});
                diana.connect(i, j);
                mocha.connect(i, j);
            }
        }
    }
    cout << ans.size() << el;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].fi << " " << ans[i].se << el;
    }
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
