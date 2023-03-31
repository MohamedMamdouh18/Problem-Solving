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
   int n , m , k, x ,ans = 0;
   cin >> n >> m ;
   vector<vector<int>> employee ;
   vector<int> empty ;
    for (int i = 0; i < n; ++i) {
        cin >> k ;
        if(k == 0) {
            empty.pb(i) ;
            continue;
        }
        vector<int> current ;
        for (int j = 0; j < k; ++j) {
            cin >> x ;
            current.pb(x) ;
            if(j > 0) connect(x , current[j-1]) ;
        }
        employee.pb(current) ;
    }
    if(employee.size() > 0){
        for (int i = 0; i < employee.size() -1 ; ++i) {
            if(is_connected(employee[i][0] , employee[i+1][0])) continue;
            ans ++ ;
            connect(employee[i][0] , employee[i+1][0]) ;
        }
    }
    
    cout << ans + empty.size() ;

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
