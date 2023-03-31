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
        array.assign(size * 2 , 0) ;
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
        array[x] = array[x * 2 + 1] + array[x * 2 + 2] ;
    }
 
    void build(vector<int> &a)
    {
        return build(a , 0 , 0 ,size) ;
    }
 
    void set(int l , int r , int v , int x , int lx , int rx)
    {
        if(rx <= l || lx >= r) return ;
        if(lx >= l && rx <= r){
            array[x] += v;
            return ;
        }
        int m = (lx + rx) /2 ;
        set(l , r , v , 2*x+1 , lx ,m) ;
        set(l , r , v , 2*x+2 , m ,rx) ;
    }
 
    void set (int l , int r , int v)
    {
        set(l , r , v , 0 , 0 ,size) ;
    }
 
    ll calc(int i,ll res ,int x , int lx , int rx)
    {
        if(rx - lx == 1) return res + array[x] ;
        int m = (lx + rx) / 2;
        if(i < m) return calc(i , res+array[x] , 2*x+1 , lx , m) ;
        else return calc(i , res+array[x] , 2*x+2 , m , rx) ;
    }
 
    ll calc(int i)
    {
        return calc(i , 0 ,0 , 0 ,size) ;
    }
};
 
int main() {
    IOS
    int n , m ;
    cin >> n >> m;
    segtree tree ;
    tree.init(n) ;
    while(m --)
    {
        int op ;
        cin >> op ;
        if(op == 1)
        {
            int l , r , v ;
            cin >> l >> r >> v ;
            tree.set(l , r , v) ;
        }
        else
        {
            int i ;
            cin >> i ;
            cout << tree.calc(i) << endl ;
        }
    }
}
