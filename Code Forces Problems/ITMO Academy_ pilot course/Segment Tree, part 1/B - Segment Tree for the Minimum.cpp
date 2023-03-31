#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
struct segtree
{
    int size ;
    vector<ll> mini ;
    void init(int n)
    {
        size = 1 ;
        while(size < n) size *= 2 ;
        mini.assign(2 * size , LONG_LONG_MAX) ;
    }
 
    void build(vector<int> &a , int x ,int lx , int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < a.size()) mini[x] = a[lx] ;
            return ;
        }
        int m = (lx+rx) / 2 ;
        build(a ,x*2 + 1 , lx , m) ;
        build(a ,x*2 + 2 , m , rx) ;
        mini[x] = min(mini[x * 2 + 1] , mini[x * 2 + 2]) ;
    }
 
    void build(vector<int> &a)
    {
        return build(a , 0 , 0 ,size) ;
    }
 
    void set(int i , int v , int x , int lx , int rx)
    {
        if(rx - lx == 1)
        {
            mini[x] = v;
            return ;
        }
        int m = (lx +rx) / 2;
        if(i < m) set(i , v , x*2+1 , lx , m) ;
        else set(i , v , x*2+2 , m , rx) ;
        mini[x] = min(mini[x * 2 + 1] , mini[x * 2 + 2]) ;
    }
 
    void set (int i , int v)
    {
        set(i , v , 0 , 0 ,size) ;
    }
 
    ll mins(int l , int r , int x , int lx , int rx)
    {
        if(lx >= r || rx <= l) return LONG_LONG_MAX ;
        if(lx >= l && rx <= r) return mini[x] ;
        int m = (lx+rx) / 2;
        ll s1 = mins(l , r , x*2+1 , lx , m) ;
        ll s2 = mins(l , r , x*2+2 , m , rx) ;
        return min(s1,s2) ;
    }
 
    ll mins(int l , int r)
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
    while(m--)
    {
        int op ;
        cin >> op ;
        if(op == 1)
        {
            int i , v;
            cin >> i >> v ;
            tree.set(i , v) ;
        }
        else
        {
            int l , r ;
            cin >> l >> r;
            cout << tree.mins(l , r) << endl ;
        }
    }
 
}
