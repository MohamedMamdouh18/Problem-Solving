#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pi>
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a , n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)     (sort(a.begin() , a.end()))
#define rev(a)  (reverse(a.begin() , a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define coutv(a)     for(int i=0; i<a.size() ; i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define isfind(a,s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)
 
 
int main() {
    IOS
    int n , k ;
    cin >> n >> k ;
    vi need(n) ;
    vi have(n) ;
    cinv(need); cinv(have);
    rep(i , 0 , 2020)
    {  int magic1 = 0 ;
       int magic2 = 0 ;
        rep(j , 0 , n)
        {
            magic1 = (i * need[j]) - have[j] ;
            if(magic1 > 0)
            {
                magic2 += magic1 ;
            }
        }
        if(magic2 > k)
        {
            cout << i - 1 ;
            return 0 ;
        }
    }
}
