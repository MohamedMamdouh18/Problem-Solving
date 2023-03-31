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
        array[x] = array[x * 2 + 1] + array[x * 2 + 2] ;
    }
 
    void set (int i , int v)
    {
        set(i , v , 0 , 0 ,size) ;
    }
 
    ll calc(int l, int r ,int x , int lx , int rx)
    {
        if(lx >= r || rx <= l) return 0 ;
        if(l <= lx && r >= rx) return array[x] ;
        int m = (lx+rx) / 2;
        int s1 = calc(l , r, x*2+1 , lx ,m);
        int s2 = calc(l , r, x*2+2 , m ,rx);
        return s1+s2 ;
    }
 
    ll calc(int  k)
    {
        return calc(k , size, 0 , 0 ,size) ;
    }
 
};
 
int main() {
    IOS
    int n ;
    cin >> n ;
    segtree tree ;
    tree.init(n) ;
    vector<int> a(n) ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] ;
    }
    vector<int> sege(n , 0) ;
    tree.build(sege) ;
    for (int i = 0; i < n; ++i) {
        cout << tree.calc(a[i]) << " " ;
        tree.set(a[i]-1 , 1) ;
    }
}
