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
    vector<ll> s ,gcdnum={0} ;
 
    ll gcd()
    {
        return gcdnum.back() ;
    }
    void push(ll x)
    {
        s.pb(x) ;
        gcdnum.pb(__gcd(x,gcdnum.back())) ;
    }
    ll pop()
    {
        ll res = s.back() ;
        s.pop_back() ;
        gcdnum.pop_back() ;
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
 
bool good()
{
    ll gcd = __gcd(s1.gcd() , s2.gcd()) ;
    return gcd == 1 ;
}
 
int main(){
   IOS
   ll n  ;
   cin >> n  ;
   vector<ll> a(n) ;
   rep(i , 0 , n) cin >>a[i] ;
 
   int l = 0 ;
   int num = 1e9 ;
   rep(r , 0 , n)
   {
        add(a[r]) ;
        while(good())
        {
            num = min(num , r-l+1) ;
            sremove() ;
            l ++ ;
        }
   }
   if(num == 1e9) cout << -1 ;
   else cout << num ;
 
}
