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
const ll mod = 1e9 + 7, N = 15 * 1e4 + 1;
int par[N];
vector<int> siz[N] ;

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        par[i] = i;
        siz[i].pb(i) ;
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

    if (siz[par_v].size() > siz[par_u].size()) swap(par_v, par_u);
    par[par_v] = par_u;
    for (int i = 0; i < siz[par_v].size(); ++i) {
        siz[par_u].pb(siz[par_v][i]) ;
    }
    siz[par_v].clear();
}

void GREEN() {
    int n , x ,y;
    cin >> n ;
    init(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y ;
        connect(x , y) ;
    }
    auto ans = siz[find_parent(1)];
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " " ;
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
