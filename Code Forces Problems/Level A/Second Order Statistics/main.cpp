#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define bsrch(a , n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)
 
 
int main() {
    IOS
    int n , l ;
    cin >> n ;
    set<int> b ;
    vector <int> a ;
    rep(i , 0 , n)
    {
        cin >> l ;
        b.insert(l) ;
    }
    for(auto element: b)
    {
        a.pb(element) ;
    }
    srt(a) ;
    if(a.size() > 1)
    {
        cout << a[1] ;
    }
    else
    {
        cout << "NO" ;
    }
}
