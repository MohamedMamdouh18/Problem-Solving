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
 
vector<pll> arr;
int siz , depth = 0;
void init(int n)
{
    siz = 1 ;
    while(siz < n)
    {
        depth ++ ;
        siz *= 2 ;
    }
 
    arr.assign(siz*2 , { 0, llm}) ;
}
 
void propagate(ll x , ll lx , ll rx , ll depth)
{
    if(arr[x].se == llm || rx - lx == 1) return ;
    arr[2*x+1].fi = arr[x].se * pow(2, depth);
    arr[2*x+1].se = arr[x].se ;
    arr[2*x+2].fi = arr[x].se * pow(2, depth);
    arr[2*x+2].se = arr[x].se ;
    arr[x].se = llm ;
}
 
void make(ll l, ll r, ll v,ll depth ,ll x, ll lx, ll rx) {
    propagate(x , lx , rx , depth -1) ;
    if(lx >= r || rx <= l) return ;
    if(lx >= l && rx <= r)
    {
        arr[x].se = v ;
        arr[x].fi = v*pow(2, depth) ;
        return ;
    }
    int m = (lx+rx) / 2 ;
    make(l , r , v , depth - 1 ,2*x+1 , lx , m);
    make(l , r , v , depth-1 ,2*x+2 , m , rx);
    arr[x].fi = arr[2*x+1].fi + arr[2*x + 2].fi ;
}
 
void make(ll l , ll r ,ll v){
    make(l , r , v , depth ,0 , 0 ,siz) ;
}
 
ll calc(ll l , ll r , ll depth, ll x , ll lx , ll rx)
{
    propagate(x , lx , rx , depth - 1) ;
    if(lx >= r || rx <= l) return 0 ;
    if(lx >= l && rx <= r) return arr[x].fi ;
 
    int m = (lx+rx) / 2 ;
    ll s1 =calc(l , r ,depth - 1 ,2*x+1 , lx , m);
    ll s2 =calc(l , r ,depth - 1 ,2*x+2 , m , rx);
    return s1 + s2 ;
}
 
ll calc(ll l , ll r)
{
    return calc(l , r ,depth , 0 , 0 , siz) ;
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
