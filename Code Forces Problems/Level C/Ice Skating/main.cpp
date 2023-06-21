#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 101, M = 20, INF = 1e-18;

vector<int> x_axis(1001), y_axis(1001);
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
    int par_u = find_parent(u);
    int par_v = find_parent(v);
    if (par_u == par_v)
        return;
    if (siz[par_u] > siz[par_v])
        swap(par_u, par_v);
    par[par_v] = par_u;
    siz[par_u] += siz[par_v];
}

void LIGHT_BLUE() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x_axis[x] != 0)
            connect(x_axis[x], i);
        else
            x_axis[x] = i;
        if (y_axis[y] != 0)
            connect(y_axis[y], i);
        else
            y_axis[y] = i;
    }
    set<int> components;
    for (int i = 1; i <= n; ++i)
        components.insert(find_parent(i));
    cout << components.size() - 1;
}

int main() {
    PREC
    IOS
    init();
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        LIGHT_BLUE();
    }
}
