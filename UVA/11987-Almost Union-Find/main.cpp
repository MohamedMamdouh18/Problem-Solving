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
int par[N];
ll sum[N];
vector<int> element[N];

void init() {
    for (int i = 0; i < N; ++i) {
        par[i] = i;
        element[i].clear();
        element[i].pb(i);
        sum[i] = i;
    }
}

int get_parent(int x) {
    if (x == par[x]) return x;
    return par[x] = get_parent(par[x]);
}

void connect(int u, int v) {
    int par_u = get_parent(u);
    int par_v = get_parent(v);
    if (par_u == par_v) return;

    if (element[par_v].size() > element[par_u].size()) swap(par_u, par_v);
    sum[par_u] += sum[par_v];
    par[par_v] = par_u;
    for (int i: element[par_v]) {
        element[par_u].pb(i);
    }
    element[par_v].clear();
}

void move(int v, int u) {
    int par_u = get_parent(u);
    int par_v = get_parent(v);
    if (par_u == par_v) return;

    if (element[par_v].size() == 1) {
        connect(u, v);
    } else {
        int buffer = element[par_v].back();
        if (buffer == v) {
            element[par_v].pop_back();
            buffer = element[par_v].back();
        }
        sum[buffer] = sum[par_v] - v, sum[par_u] += v;
        par[v] = par_u, element[par_u].pb(v);
        if(buffer != par_v){
            element[buffer].clear();
            for (int i: element[par_v]) {
                if (i == v) continue;
                element[buffer].pb(i);
                par[i] = buffer;
            }
            element[par_v].clear();
        }else{
            vector<int> b ;
            for (int i: element[buffer]) {
                if (i == v) continue;
                b.pb(i);
                par[i] = buffer;
            }
            element[buffer].clear() ;
            element[buffer] = b ;
        }
    }
}


void GREEN() {
    int n, m, op, x, y;
    while (cin >> n >> m) {
        init();
        for (int i = 0; i < m; ++i) {
            cin >> op;
            if (op == 3) {
                cin >> x;
                int p = get_parent(x);
                cout << element[p].size() << " " << sum[p] << el;
            } else if (op == 2) {
                cin >> x >> y;
                move(x, y);
            } else {
                cin >> x >> y;
                connect(x, y);
            }
        }
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
