#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
struct segtree
{
    int size = 1;
    vector<ll> array ;
 
    void init(int n)
    {
        while(size < n) size *= 2 ;
        array.resize(size * 2) ;
    }
 
 
    void build(vector<int> &a , int x ,int lx , int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < a.size()) array[x] = a[lx] ;
            return ;
        }
        int m = (lx+rx) / 2 ;
        build(a ,x*2 + 1 , lx , m) ;
        build(a ,x*2 + 2 , m , rx) ;
        array[x] = max(array[x * 2 + 1] , array[x * 2 + 2]) ;
    }
 
    void build(vector<int> &a)
    {
        return build(a , 0 , 0 ,size) ;
    }
 
    void set(int i , int v , int x , int lx , int rx)
    {
        if(rx - lx == 1)
        {
            array[x] = v;
            return ;
        }
        int m = (lx +rx) / 2;
        if(i < m) set(i , v , x*2+1 , lx , m) ;
        else set(i , v , x*2+2 , m , rx) ;
        array[x] = max(array[x * 2 + 1] , array[x * 2 + 2]) ;
    }
 
    void set (int i , int v)
    {
        set(i , v , 0 , 0 ,size) ;
    }
 
    ll calc(ll k, ll l ,int x , int lx , int rx)
    {
       if(l >= rx && l > lx) return -1 ;
       if(array[x] < k) return -1 ;
       if(rx- lx == 1) return lx ;
       int m = (lx+rx) / 2;
       int res = calc(k ,l , 2*x+1 , lx , m) ;
 
       if(res == -1) res =  calc(k ,l , 2*x+2 , m , rx) ;
 
       return res ;
    }
 
    ll calc(ll  k , ll l)
    {
        return calc(k , l, 0 , 0 ,size) ;
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
        if(op == 1 )
        {
            int i  , v;
            cin >> i >> v ;
            tree.set(i , v) ;
        }
        else
        {
            ll k , l;
            cin >> k >> l;
            cout << tree.calc(k , l) << endl ;
        }
    }
}
