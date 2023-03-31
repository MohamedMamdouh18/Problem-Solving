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
    if (v_par == u_par) {
        cycle = true;
        return;
    }
    if (siz[v_par] < siz[u_par]) swap(v_par, u_par);
    par[u_par] = par[v_par];
    siz[v_par] += siz[u_par];
}

void GREEN() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<pair<char, char>> ans;
    for (int i = 0; i < n; ++i) {
        int v = s1[i] - 'a', u = s2[i] - 'a';
        if (is_connected(u, v)) continue;
        connect(u, v);
        ans.pb({u + 'a', v + 'a'});
    }
    cout << ans.size() << el;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].fi << " " << ans[i].se << el;
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
