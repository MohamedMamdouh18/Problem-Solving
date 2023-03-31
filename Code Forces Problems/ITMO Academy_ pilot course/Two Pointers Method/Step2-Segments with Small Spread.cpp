#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define srt(a)     (sort(a.begin() , a.end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
 
struct stacki {
    vector<ll> s ,mini = {LLONG_MAX} , maxi={LLONG_MIN} ;
 
    ll smin(){
        return mini.back() ;
    }
    ll smax(){
        return maxi.back() ;
    }
    void push(ll x)
    {
        s.pb(x) ;
        mini.pb(min(mini.back() , x)) ;
        maxi.pb(max(x , maxi.back())) ;
    }
    ll pop()
    {
        ll res = s.back() ;
        s.pop_back() ;
        mini.pop_back() ;
        maxi.pop_back() ;
        return res ;
    }
    bool sempty()
    {
        return s.empty() ;
    }
};
 
stacki s1 , s2 ;
 
void add(ll x)
{
    s1.push(x) ;
}
 
void sremove()
{
    if(s2.sempty())
    {
        while(!s1.sempty())
        {
            s2.push(s1.pop()) ;
        }
    }
    s2.pop() ;
}
 
bool good(ll k)
{
    ll a = min(s1.smin() , s2.smin());
    ll b = max(s1.smax() , s2.smax());
    return b-a <= k ;
}
 
int main(){
   IOS
   ll n , k ;
   cin >> n >> k ;
   vector<ll> a(n) ;
   rep(i , 0 , n) cin >>a[i] ;
 
   int l = 0 ;
   ll num = 0 ;
   rep(r , 0 , n)
   {
        add(a[r]) ;
        while(!good(k))
        {
            sremove() ;
            l ++ ;
        }
        num += r-l+1 ;
   }
   cout<< num ;
 
}
