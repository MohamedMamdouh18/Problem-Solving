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
 
const ll MOD = 1000000007 ;
 
vector<pll> arr;
int siz;
 
void init(int n)
{
    siz = 1 ;
    while(siz < n) siz *= 2 ;
    arr.assign(siz*2 , {1 , 1}) ;
}
 
void build(int l , int r , int x , int lx , int rx)
{
    if(rx - lx == 1) return ;
    int m = (lx+rx) / 2 ;
    build(l , r , 2*x+1 , lx , m);
    build(l , r , 2*x+2 , m , rx);
    arr[x].fi = arr[2*x+1].fi + arr[2*x+2].fi ;
}
 
void make(ll l, ll r, ll v, ll x, ll lx, ll rx) {
    if(lx >= r || rx <= l) return ;
    if(lx >= l && rx <= r)
    {
        arr[x].fi = (arr[x].fi * v) % MOD ;
        if(arr[x].se == 1) arr[x].se = v ;
        else arr[x].se = (arr[x].se * v) % MOD ;
        return ;
    }
    int m = (lx+rx) / 2 ;
    make(l , r , v , 2*x+1 , lx , m);
    make(l , r , v , 2*x+2 , m , rx);
    arr[x].fi = ((arr[2*x+1].fi * arr[x].se) %MOD+ (arr[2*x+2].fi * arr[x].se) %MOD) % MOD ;
}
 
void make(ll l , ll r ,ll v){
    make(l , r , v , 0 , 0 ,siz) ;
}
 
ll calc(ll l , ll r , ll x , ll mult ,ll lx , ll rx)
{
    if(lx >= r || rx <= l) return 0 ;
    if(lx >= l && rx <= r) return arr[x].fi*mult ;
 
    int m = (lx+rx) / 2 ;
    ll s1 =calc(l , r , 2*x+1 , (arr[x].se*mult)%MOD , lx , m);
    ll s2 =calc(l , r , 2*x+2 , (arr[x].se*mult)%MOD, m , rx);
    return (s1 + s2) % MOD ;
}
 
ll calc(ll l , ll r)
{
    return calc(l , r , 0 , 1 , 0 , siz) ;
}
 
int main() {
    IOS
    ll n , m;
    cin >> n >> m;
    init(n) ;
    build(0 , siz, 0 , 0 , siz) ;
    while(m --)
    {
        int op ;
        cin >> op ;
        if(op == 1)
        {
            ll l , r , v ;
            cin >> l >> r >> v ;
            make(l , r , v) ;
        }
        else
        {
            ll l , r ;
            cin >> l >> r ;
            cout << calc(l, r)<< endl ;
        }
    }
}
