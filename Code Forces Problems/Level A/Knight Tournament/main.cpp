#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<pair<int , bool>> seg_tree;
int siz ;
void init(int n)
{
    siz = 1 ;
    while(siz < n) siz *= 2 ;
    seg_tree.assign(siz*2 , {0,false}) ;
}

pair<int , bool> merge(pair<int , bool> a , pair<int , bool> b)
{
    if(a.se && b.se) return {0 , true} ;
    return {0 , false} ;
}

void make(ll l, ll r , ll v,ll x, ll lx, ll rx) {
    if(seg_tree[x].se) return ;
    if(lx >= r || rx <= l) return ;
    if(rx - lx == 1)
    {
        if(!(lx == v-1)) seg_tree[x] = {v , true} ;
        return ;
    }
    ll m = (lx+rx) / 2 ;
    make(l , r , v ,2*x+1 , lx , m);
    make(l , r , v ,2*x+2 , m , rx);
    seg_tree[x] = merge(seg_tree[2*x+1] , seg_tree[2*x+2]) ;
}

void make(ll l , ll r , ll v){
    make(l , r , v , 0 , 0 ,siz) ;
}

int main() {
    IOS
    ll n , m;
    cin >> n >> m;
    init(n) ;
    while(m --)
    {
        int l , r , x ;
        cin >> l >> r >> x ;
        make(l-1 , r , x) ;
    }
    for (int i = 0; i < n; ++i) {
        cout << seg_tree[i+siz-1].first << " " ;
    }
}
