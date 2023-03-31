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
 
struct segtree
{
    int size ;
    vector<ll> mini ;
 
    void init(int n)
    {
        size = 1 ;
        while(size < n) size *= 2 ;
        mini.resize(size*2) ;
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
        mini[x] = mini[x * 2 + 1] + mini[x * 2 + 2] ;
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
        mini[x] =mini[x * 2 + 1] + mini[x * 2 + 2] ;
    }
 
    void set (int i , int v)
    {
        set(i , v , 0 , 0 ,size) ;
    }
 
    ll calc(int k, int x , int lx , int rx)
    {
       if(rx- lx == 1) return lx ;
       int m1 = mini[2*x+1] ;
       int m = (lx+rx) / 2;
       if(k < m1) return calc(k , 2*x+1 , lx , m) ;
       else return calc(k-m1 , 2*x+2 , m , rx) ;
    }
 
    ll calc(int  k)
    {
        return calc(k , 0 , 0 ,size) ;
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
            int i ;
            cin >> i ;
            a[i] = !a[i] ;
            tree.set(i , a[i]) ;
        }
        else
        {
            int k ;
            cin >> k ;
            cout << tree.calc(k) << endl ;
        }
    }
}
