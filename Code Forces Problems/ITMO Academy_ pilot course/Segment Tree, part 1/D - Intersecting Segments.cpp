
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
 
    ll calc(int l , int r,int x , int lx , int rx)
    {
        if(lx >= r || rx <= l) return 0 ;
        if(lx >= l && rx <= r) return array[x] ;
        int m = (lx+rx) / 2;
        int s1 = calc(l , r , x*2+2 , m , rx) ;
        int s2 = calc(l , r , x*2+1 , lx , m) ;
        return s1+s2;
    }
 
    ll calc(int  l , int r)
    {
        return calc(l , r , 0 , 0 ,size) ;
    }
 
};
 
int main() {
    IOS
    int n ;
    cin >> n ;
    segtree tree ;
    tree.init(n*2) ;
    vector<int> a(n*2) ;
    vector<int> ans1(n , -1) ;
    vector<int> ans2(n , -1) ;
    for (int i = 0; i < n*2; ++i) {
        cin >> a[i] ;
        a[i] -- ;
    }
 
    for (int i = 0; i < n*2; ++i) {
        if(ans1[a[i]] == -1)
        {
            ans1[a[i]] = i ;
            tree.set(i , 1) ;
        }
        else
        {
            tree.set(ans1[a[i]] , 0) ;
            int val = tree.calc(ans1[a[i]] , i) ;
            ans1[a[i]] = val ;
        }
    }
 
    tree.init(n*2) ;
 
    for (int i = 2*n-1; i >= 0; --i) {
        if(ans2[a[i]] == -1)
        {
            ans2[a[i]] = i ;
            tree.set(i , 1) ;
        }
        else
        {
            tree.set(ans2[a[i]] , 0) ;
            int val = tree.calc(i , ans2[a[i]]) ;
            ans2[a[i]] = val ;
        }
    }
 
    for (int i = 0; i < n; ++i) {
        cout << ans1[i]+ans2[i]<< " " ;
    }
 
}
