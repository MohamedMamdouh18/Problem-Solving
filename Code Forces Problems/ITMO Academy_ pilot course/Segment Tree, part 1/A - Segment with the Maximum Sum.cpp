#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
struct item{
    ll seg , pref , suf , sum ;
};
 
struct segtree
{
    int size ;
    vector<item> mini ;
 
    void init(int n)
    {
        size = 1 ;
        while(size < n) size *= 2 ;
        mini.resize(size*2) ;
    }
 
    item comp(item a ,item b)
    {
        return {max(max(a.seg , b.seg) , a.suf+b.pref)
        ,   max(a.pref , a.sum+b.pref)
        ,   max(b.suf , b.sum+a.suf)
        , a.sum + b.sum
        } ;
    }
    item single(int v)
    {
        if(v > 0) return{v , v , v , v} ;
        else return{0 , 0 , 0 , v} ;
    }
 
    void build(vector<int> &a , int x ,int lx , int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < a.size()) mini[x] = single(a[lx]) ;
            return ;
        }
        int m = (lx+rx) / 2 ;
        build(a ,x*2 + 1 , lx , m) ;
        build(a ,x*2 + 2 , m , rx) ;
        mini[x] = comp(mini[x * 2 + 1] , mini[x * 2 + 2]) ;
    }
 
    void build(vector<int> &a)
    {
        return build(a , 0 , 0 ,size) ;
    }
 
    void set(int i , int v , int x , int lx , int rx)
    {
        if(rx - lx == 1)
        {
            mini[x] = single(v);
            return ;
        }
        int m = (lx +rx) / 2;
        if(i < m) set(i , v , x*2+1 , lx , m) ;
        else set(i , v , x*2+2 , m , rx) ;
        mini[x] = comp(mini[x * 2 + 1] , mini[x * 2 + 2]) ;
    }
 
    void set (int i , int v)
    {
        set(i , v , 0 , 0 ,size) ;
    }
 
    item mins(int l , int r , int x , int lx , int rx)
    {
        if(lx >= r || rx <= l) return {0 , 0 , 0 , 0} ;
        if(lx >= l && rx <= r) return mini[x] ;
        int m = (lx+rx) / 2;
        item s1 = mins(l , r , x*2+1 , lx , m) ;
        item s2 = mins(l , r , x*2+2 , m , rx) ;
        return comp(s1,s2) ;
    }
 
    item mins(int l , int r)
    {
        return mins(l , r , 0 , 0 ,size) ;
    }
 
};
 
int main() {
    IOS
    int m , n ;
    cin >> n >> m ;
    segtree tree ;
    tree.init(n) ;
    vector<int> a(n) ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] ;
    }
    tree.build(a) ;
    item out = tree.mins(0 , n) ;
    cout << out.seg << endl ;
    while(m--)
    {
        int i , v ;
        cin >> i >> v ;
        tree.set(i , v);
        item out = tree.mins(0 , n) ;
        cout << out.seg << endl ;
    }
}
