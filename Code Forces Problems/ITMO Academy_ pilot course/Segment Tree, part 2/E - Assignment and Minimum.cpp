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
int siz;
void init(int n)
{
    siz = 1 ;
    while(siz < n) siz *= 2 ;
 
    arr.assign(siz*2 , { 0, llm}) ;
}
 
void propagate(ll x , ll lx , ll rx)
{
    if(arr[x].se == llm || rx - lx == 1) return ;
    arr[2*x+1].fi = arr[x].se ;
    arr[2*x+1].se = arr[x].se ;
    arr[2*x+2].fi = arr[x].se ;
    arr[2*x+2].se = arr[x].se ;
    arr[x].se = llm ;
}
 
void make(ll l, ll r, ll v, ll x, ll lx, ll rx) {
    propagate(x , lx , rx) ;
    if(lx >= r || rx <= l) return ;
    if(lx >= l && rx <= r)
    {
        arr[x].se = v ;
        arr[x].fi = v ;
        return ;
    }
    int m = (lx+rx) / 2 ;
    make(l , r , v , 2*x+1 , lx , m);
    make(l , r , v , 2*x+2 , m , rx);
    arr[x].fi = min(arr[2*x+1].fi , arr[2*x + 2].fi) ;
}
 
void make(ll l , ll r ,ll v){
    make(l , r , v , 0 , 0 ,siz) ;
}
 
ll calc(ll l , ll r , ll x ,ll lx , ll rx)
{
    propagate(x , lx , rx) ;
    if(lx >= r || rx <= l) return llm ;
    if(lx >= l && rx <= r) return arr[x].fi ;
 
    int m = (lx+rx) / 2 ;
    ll s1 =calc(l , r , 2*x+1 , lx , m);
    ll s2 =calc(l , r , 2*x+2 , m , rx);
    return min(s1 , s2);
}
 
ll calc(ll l , ll r)
{
    return calc(l , r , 0 , 0 , siz) ;
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
