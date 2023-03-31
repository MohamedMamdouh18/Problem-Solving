#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll , ll>
#define pb push_back
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
struct item
{
    ll l = 0 ;
    ll r = 0 ;
    ll d = 0 ;
};

vector<ll> seg_tree;
vector<ll> ques ;
int siz ;
void init(int n)
{
    siz = 1 ;
    while(siz < n) siz *= 2 ;
    seg_tree.assign(siz*2 , 0) ;
}

void build(ll x , ll lx , ll rx)
{
    if(rx - lx == 1)
    {
        if(lx < ques.size()) seg_tree[x] =ques[lx] ;
        return ;
    }
    ll m = (lx+rx) / 2 ;
    build(x*2+1 , lx , m) ;
    build(x*2+2 , m , rx) ;
}

void build()
{
    build(0 , 0 , siz) ;
}

void update(ll l , ll r , ll v , ll x , ll lx , ll rx)
{
    if(lx >=r || rx <= l) return ;
    if(lx >= l && rx <= r)
    {
        seg_tree[x] += v ;
        return ;
    }
    ll m = (lx+rx) / 2;
    update(l , r , v , 2*x+1 , lx , m);
    update(l , r , v , 2*x+2 , m , rx);
}

void update(ll l , ll r ,ll v)
{
    update(l , r , v , 0 , 0 , siz);
}

ll get(ll i , ll num ,ll x , ll lx , ll rx)
{
    if(rx - lx == 1) return seg_tree[x] + num ;
    ll m = (lx+rx) / 2;
    if(i<m) return get(i , num+seg_tree[x] , 2*x+1 , lx , m);
    else return get(i , num+seg_tree[x], 2*x+2 , m , rx);
}


ll get(ll i)
{
    return get(i , 0 , 0 , 0 , siz) ;
}

int main() {
    IOS
    ll n , m, k;
    cin >> n >> m >> k;
    init(n) ;
    for (int i = 0; i < n; ++i) {
        ll x ;
        cin >> x ;
        ques.pb(x) ;
    }
    build() ;
    vector<item> quer(m) ;
    for (int i = 0; i < m; ++i) {
        cin >> quer[i].l >> quer[i].r >> quer[i].d ;
        quer[i].l -- ;
    }
    vector<ll> start(m+1) ;
    for (int i = 0; i < k; ++i) {
        ll x , y ;
        cin >> x >> y ;
        start[--x] ++ ;
        start[y] -- ;
    }
    ll num = 0 ;
    for (int i = 0; i < m; ++i) {
        num += start[i] ;
        update(quer[i].l , quer[i].r , quer[i].d * num) ;
    }
    for (int i = 0; i < n; ++i) {
        cout << get(i) << " " ;
    }
}
