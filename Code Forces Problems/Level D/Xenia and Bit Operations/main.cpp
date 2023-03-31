#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll , ll>
#define pb push_back
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<pll> seg_tree;
vector<ll> ques ;
int siz ;
void init(int n)
{
    siz = n;
    seg_tree.assign(siz*2 , {0,1}) ;
}

pll merge(pll a , pll b)
{
    if(a.se && b.se) return {a.fi ^ b.fi , 0} ;
    return{a.fi | b.fi , 1} ;
}

void build(ll x , ll lx , ll rx)
{
    if(rx - lx == 1)
    {
        if(lx < ques.size()) seg_tree[x] ={ques[lx] , 0} ;
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

void update(ll i , ll v , ll x , ll lx , ll rx)
{
    if(rx - lx == 1)
    {
        seg_tree[x] = {v , 0} ;
        return ;
    }
    ll m = (lx+rx) / 2 ;
    if(i<m) update(i , v , 2*x+1 , lx , m);
    else update(i , v , 2*x+2 , m , rx);
    seg_tree[x] = merge(seg_tree[2*x+1] , seg_tree[2*x+2]) ;
}

void update(ll i , ll v)
{
    update(i , v , 0 , 0 , siz);
}

int main() {
    IOS
    ll n , m;
    cin >> n >> m;
    n = pow(2,n) ;
    init(n) ;
    for (int i = 0; i < n; ++i) {
        ll x ;
        cin >> x ;
        ques.pb(x) ;
    }
    build() ;
    while(m--)
    {
        ll i ,  v ;
        cin >> i >> v;
        update(i-1 , v) ;
        cout << seg_tree[0].first << endl ;
    }
}
