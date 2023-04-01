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
const ll mod = 1e9, N = 2 * 1e5 + 1;
ll par[N] ,siz[N] ;
void init(){
    for (int i = 0; i < N; ++i) {
        par[i] = i ;
        siz[i] = 1 ;
    }
}

int find_parent(int x){
    if(par[x] == x) return x ;
    return par[x] = find_parent(par[x]) ;
}

bool is_connected(int u , int v){
    return find_parent(u)== find_parent(v);
}

void connect(int u , int v){
    int par_v = find_parent(v);
    int par_u = find_parent(u);
    if(par_v == par_u) return;

    if(siz[par_v] > siz[par_u]) swap(par_u , par_v) ;
    par[par_v] = par_u ;
    siz[par_u] += siz[par_v] ;
}

void GREEN() {
    int n , m ,x,y,w;
    cin >> n >> m ;
    init() ;
    vector<pair<int,pair<int,int>>> edge(m) ;
    ll tot = 0 , ans = 0 ;
    for (int i = 0; i < m; ++i) {
        cin >> edge[i].se.fi >> edge[i].se.se >> edge[i].fi ;
        tot += edge[i].fi ;
    }
    sort(edge.rbegin() , edge.rend());
    for (int i = 0; i < m; ++i) {
        x = edge[i].se.fi ,y = edge[i].se.se ;
        w = edge[i].fi ;
        if(!is_connected(x , y)){
            ll cnt = siz[find_parent(x)] * siz[find_parent(y)] ;
            ans += (((cnt % mod) * (tot % mod)) % mod) ;
            ans %= mod ;
            connect(x , y) ;
        }
        tot -= w ;
    }
    cout << ans ;
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
