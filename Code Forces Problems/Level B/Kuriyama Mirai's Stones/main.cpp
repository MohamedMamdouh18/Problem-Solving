
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n , num , type , l , r;
    cin >> n ;
    vector <int> a(n + 1) ;
    vector <ll> as(n + 1) ;
    vector <ll> bs(n + 1) ;
    rep(i , 1 , n+1)
    {
        cin >> a[i] ;
    }
    rep(i , 1 , n+1)
    {
        as[i] = as[i-1] +a[i] ;
    }
    srt(a) ;
    rep(i , 1 , n+1)
    {
        bs[i] = bs[i-1] +a[i] ;
    }
    cin >> num ;
    while(num --)
    {
        cin >> type >> l >> r ;
        if(type == 1)
        {
            cout << as[r] - as[l-1] <<endl ;
        }
        else
        {
            cout << bs[r] - bs[l-1] <<endl ;
        }
    }
}
