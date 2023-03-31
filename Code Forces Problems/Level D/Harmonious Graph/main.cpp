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

bool cycle = false;
int par[N], siz[N];

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
    if (v_par < u_par) swap(v_par, u_par);
    par[u_par] = par[v_par];
    siz[v_par] += siz[u_par];
}


void GREEN() {
    int n, m, x, y, maxi = INT_MIN, mini = INT_MAX, ans = 0;
    cin >> n >> m;
    map<int, bool> exist;
    init(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        connect(x, y);
        maxi = max({maxi, x, y});
        mini = min({mini, x, y});
        exist[x] = exist[y] = true;
    }
    int cur = -1;
    for (int i = mini; i <= maxi; ++i) {
        if (cur != -1) {
            if (i == cur)cur = -1;
            else if (!is_connected(cur, i)) {
                connect(cur, i);
                ans++;
                cur = find_parent(i);
            }
        } else if (exist[i]) cur = find_parent(i);
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
