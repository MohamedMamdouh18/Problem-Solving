#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pll pair<ll , ll>
#define llm LONG_LONG_MAX
#define pb push_back
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
vector<pll> seg_tree;
vector<ll> ques ;
int siz ;
void init(int n)
{
    siz = 1 ;
    while(siz < n) siz *= 2 ;
    seg_tree.assign(siz*2 , {0 , llm}) ;
}
 
void propagate(ll x , ll lx , ll rx)
{
    if(seg_tree[x].se == llm || rx-lx == 1) return ;
    seg_tree[2*x+1].fi = seg_tree[x].se ;
    seg_tree[2*x+2].fi = seg_tree[x].se ;
    seg_tree[2*x+1].se = seg_tree[x].se ;
    seg_tree[2*x+2].se = seg_tree[x].se ;
    seg_tree[x].se = llm ;
}
 
pll merge(pll a , pll b)
{
    return{max(a.fi , b.fi) , llm} ;
}
 
void build(ll x , ll lx , ll rx)
{
    if(rx - lx == 1)
    {
        if(lx < ques.size()) seg_tree[x].fi =ques[lx] ;
        return ;
    }
    ll m = (lx+rx) / 2 ;
    build(x*2+1 , lx , m) ;
    build(x*2+2 , m , rx) ;
    seg_tree[x] = merge(seg_tree[2*x+1] , seg_tree[2*x+2]) ;
}
 
void build()
{
    build(0 , 0 , siz) ;
}
 
void update(ll l , ll r , ll v , ll x , ll lx , ll rx)
{
    propagate(x , lx , rx) ;
    if(lx >=r || rx <= l) return ;
    if(lx >= l && rx <= r)
    {
        seg_tree[x].fi = v ;
        seg_tree[x].se = v ;
        return ;
    }
    ll m = (lx+rx) / 2;
    update(l , r , v , 2*x+1 , lx , m);
    update(l , r , v , 2*x+2 , m , rx);
    seg_tree[x] = merge(seg_tree[2*x+1] , seg_tree[2*x+2]) ;
}
 
void update(ll l , ll r ,ll v)
{
    update(l , r , v , 0 , 0 , siz);
}
 
ll calc(ll l, ll r , ll x ,ll lx , ll rx)
{
    propagate(x , lx , rx) ;
    if(lx >= r || rx <= l) return LONG_LONG_MIN ;
    if(lx >= l && rx <= r) return seg_tree[x].fi ;
    ll m = (lx+rx) / 2 ;
    ll s1 = calc(l , r , 2*x+1 , lx ,m) ;
    ll s2 = calc(l , r , 2*x+2 , m ,rx) ;
    return max(s1 , s2) ;
}
 
ll calc(ll l , ll r)
{
    return calc(l , r , 0 , 0 ,siz) ;
}
 
int main() {
    IOS
    ll n , m ;
    cin >>  n ;
    for (int i = 0; i < n; ++i) {
        ll x ;
        cin >> x ;
        ques.pb(x) ;
    }
    init(n) ;
    build() ;
    cin >> m ;
    for (int i = 0; i < m; ++i) {
        ll w , h ;
        cin >> w >> h;
        ll maxi = calc(0 , w) ;
        update(0 , w , maxi + h) ;
        cout << maxi << endl ;
    }
}
