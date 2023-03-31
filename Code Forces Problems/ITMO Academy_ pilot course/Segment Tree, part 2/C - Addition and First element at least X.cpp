#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define llm LONG_LONG_MAX
#define pi pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
vector<pair<ll , ll>> arr;
int siz ;
void init(int n)
{
    siz = 1 ;
    while(siz < n) siz *= 2 ;
    arr.assign(siz*2 , {0,0}) ;
}
 
void propagate(ll x , ll lx , ll rx)
{
    if(rx - lx == 1 || arr[x].se == 0) return ;
    arr[2*x+1].fi += arr[x].se  ;
    arr[2*x+1].se += arr[x].se ;
    arr[2*x+2].fi += arr[x].se  ;
    arr[2*x+2].se += arr[x].se ;
    arr[x].se = 0 ;
}
 
pll merge(pll a , pll b)
{
    return{max(a.fi , b.fi), 0} ;
}
 
void make(ll l, ll r , ll v,ll x, ll lx, ll rx) {
    propagate(x , lx , rx) ;
    if(lx >= r || rx <= l) return ;
    if(lx >= l && rx <= r)
    {
       arr[x].fi += v ;
       arr[x].se += v ;
       return ;
    }
    ll m = (lx+rx) / 2 ;
    make(l , r , v ,2*x+1 , lx , m);
    make(l , r , v ,2*x+2 , m , rx);
    arr[x].fi = max(arr[2*x+1].fi , arr[2*x+2].fi) ;
}
 
void make(ll l , ll r , ll v){
    make(l , r , v , 0 , 0 ,siz) ;
}
 
ll calc(ll k , ll l, ll x , ll lx , ll rx)
{
    propagate(x , lx , rx) ;
    if(rx <= l) return -1 ;
    if(arr[x].fi < k) return -1 ;
    if(rx - lx == 1) return lx ;
    ll m = (rx+lx) / 2 ;
    ll res = calc(k , l , 2*x+1 , lx , m) ;
    if(res == -1) res = calc(k , l , 2*x+2 , m , rx) ;
 
    return res ;
}
 
ll calc(ll x , ll l)
{
    return calc(x , l ,0 , 0 , siz) ;
}
 
int main() {
    IOS
    ll n , m;
    cin >> n >> m;
    init(n) ;
    while(m --)
    {
        int op ;
        cin >> op ;
        if(op == 1)
        {
            ll l , r , v;
            cin >> l >> r >> v;
            make(l , r , v) ;
        }
        else
        {
            ll x , l ;
            cin >> x >> l  ;
            cout << calc(x , l) << endl ;
        }
    }
}
