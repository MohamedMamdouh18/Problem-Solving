
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define pb push_back
#define mp make_pair
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    int n , m , mincount = 0 , maxcount = 0;
    cin >> n >> m ;
    vector<int> a(m) ;
    vector<int> b(m) ;
    rep(i , 0 , m)
    {
        cin >> a[i] ;
        b[i] = a[i] ;
    }
    srt(a) ;
    srt(b) ;
    rep(i , 0 , n)
    {
        if(a.front() == 0) a.erase(a.begin()) ;
        mincount += a.front() ;
        a.front() -- ;
    }
    rep(i , 0 , n)
    {
        maxcount += b.back() ;
        b.back() -- ;
        srt(b) ;
    }
    cout <<maxcount <<" " << mincount ;

}
