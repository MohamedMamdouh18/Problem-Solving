#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define llm LONG_LONG_MAX
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
struct segtree
{
    int size = 1;
    vector<pair<ll,ll>> array ;
 
    void init(int n)
    {
        while(size < n) size *= 2 ;
        array.resize(size * 2) ;
    }
 
 
    void set(int l , int r , int v,  int x , int lx , int rx)
    {
        if(rx <= l || lx >= r) return ;
        if(lx >= l && rx <= r){
            array[x].first += v;
            array[x].second += v ;
            return ;
        }
        int m = (lx + rx) /2 ;
        set(l , r , v , 2*x+1 , lx ,m) ;
        set(l , r , v , 2*x+2 , m ,rx) ;
        array[x].first = min(array[2*x+1].first , array[2*x+2].first) + array[x].second ;
    }
 
    void set (int l , int r , int v)
    {
        set(l , r , v ,0 , 0 ,size) ;
    }
 
    ll calc(int l , int r, ll num ,int x , int lx , int rx)
    {
        if(rx <= l || lx >= r) return llm;
        if(lx >= l && rx <= r){
            return num + array[x].first ;
        }
        int m = (lx+rx) / 2;
        ll s1 = calc(l , r , num+array[x].second ,2*x+1 , lx , m) ;
        ll s2 = calc(l , r , num+array[x].second ,2*x+2 , m , rx) ;
        return min(s1,s2) ;
    }
 
    ll calc(int l , int r)
    {
        return calc(l , r ,0 , 0 , 0 ,size) ;
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
            int l , r ;
            cin >> l >> r ;
            cout << tree.calc(l , r) << endl ;
        }
    }
}
