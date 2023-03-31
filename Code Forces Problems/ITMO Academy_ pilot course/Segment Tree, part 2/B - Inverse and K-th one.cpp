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
 
vector<pair<ll , bool>> arr;
int siz , depth = 0;
void init(int n)
{
    siz = 1 ;
    while(siz < n)
    {
        depth ++ ;
        siz *= 2 ;
    }
    arr.assign(siz*2 , {0,false}) ;
}
 
pll single(ll x ,ll dep)
{
    ll sum = pow(2 , dep) ;
    return{sum - arr[x].fi , true} ;
}
 
void propagate(ll x , ll lx , ll rx , ll dep)
{
    if(rx - lx == 1 || !arr[x].se) return ;
    arr[2*x+1].fi = pow(2 , dep) -arr[2*x+1].fi  ;
    arr[2*x+1].se = ! arr[2*x+1].se ;
    arr[2*x+2].fi = pow(2 , dep) -arr[2*x+2].fi  ;
    arr[2*x+2].se = ! arr[2*x+2].se ;
    arr[x].se = false ;
}
 
pll merge(pll a , pll b)
{
    return{a.fi+b.fi , false} ;
}
 
void make(ll l, ll r,ll dep ,ll x, ll lx, ll rx) {
    propagate(x , lx , rx , dep -1) ;
    if(lx >= r || rx <= l) return ;
    if(lx >= l && rx <= r)
    {
       arr[x] = single(x , dep) ;
       return ;
    }
    ll m = (lx+rx) / 2 ;
    make(l , r , dep-1 ,2*x+1 , lx , m);
    make(l , r , dep-1 ,2*x+2 , m , rx);
    arr[x] = merge(arr[2*x+1] , arr[2*x+2]) ;
}
 
void make(ll l , ll r){
    make(l , r , depth ,0 , 0 ,siz) ;
}
 
ll calc(ll k, ll dep, ll x , ll lx , ll rx)
{
    propagate(x , lx , rx , dep - 1) ;
    if(rx - lx == 1) return lx ;
    ll val = arr[2*x+1].fi ;
    ll m = (lx+rx) / 2 ;
    if(k < val) return calc(k , dep-1 , 2*x+1 , lx , m) ;
    else return calc(k-val , dep-1 , 2*x+2 , m , rx) ;
}
 
ll calc(ll k)
{
    return calc(k,depth , 0 , 0 , siz) ;
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
            int l , r ;
            cin >> l >> r ;
            make(l , r) ;
        }
        else
        {
            ll k ;
            cin >> k  ;
            cout << calc(k) << endl ;
        }
    }
}
