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
 
struct item{
    ll seg ;
    ll pref ;
    ll suf ;
    ll sum ;
    ll operation ;
};
 
vector<item> arr;
int siz , depth = 0;
void init(int n)
{
    siz = 1 ;
    while(siz < n)
    {
        depth ++ ;
        siz *= 2 ;
    }
    arr.resize(siz*2) ;
}
 
item single(ll v , ll dep)
{
    if(v > 0) return {static_cast<long long>(v * pow(2,dep)) ,static_cast<long long>(v * pow(2,dep)),static_cast<long long>(v * pow(2,dep))
                ,static_cast<long long>(v * pow(2,dep)) , v} ;
    return {0,0,0,static_cast<long long>(v * pow(2,dep)) , v} ;
}
 
 
void propagate(ll x , ll lx , ll rx , ll depth)
{
    if(rx - lx == 1 || arr[x].operation == llm) return ;
    arr[2*x+1] = single(arr[x].operation , depth) ;
    arr[2*x+2] = single(arr[x].operation , depth) ;
    arr[x].operation = llm ;
}
 
item merge(item a , item b)
{
    return {max(max(a.seg , b.seg) , a.suf + b.pref)
    , max(a.pref , a.sum + b.pref)
    , max(b.suf , b.sum + a.suf)
    , a.sum + b.sum
    , llm};
}
 
void make(ll l, ll r, ll v,ll depth ,ll x, ll lx, ll rx) {
    propagate(x , lx , rx , depth -1) ;
    if(lx >= r || rx <= l) return ;
    if(lx >= l && rx <= r)
    {
       arr[x] = single(v , depth) ;
        return ;
    }
    int m = (lx+rx) / 2 ;
    make(l , r , v , depth - 1 ,2*x+1 , lx , m);
    make(l , r , v , depth-1 ,2*x+2 , m , rx);
    arr[x] = merge(arr[2*x+1] , arr[2*x+2]) ;
}
 
void make(ll l , ll r ,ll v){
    make(l , r , v , depth ,0 , 0 ,siz) ;
}
 
item calc(ll l , ll r , ll depth, ll x , ll lx , ll rx)
{
    propagate(x , lx , rx , depth - 1) ;
    if(lx >= r || rx <= l) return {0,0,0,0,llm} ;
    if(lx >= l && rx <= r) return arr[x] ;
 
    int m = (lx+rx) / 2 ;
    item s1 =calc(l , r ,depth - 1 ,2*x+1 , lx , m);
    item s2 =calc(l , r ,depth - 1 ,2*x+2 , m , rx);
    return merge(s1 , s2) ;
}
 
item calc(ll l , ll r)
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
        int l ,r , v ;
        cin >> l >> r >> v ;
        make(l , r , v) ;
        cout << calc(0,siz).seg << endl ;
    }
}
