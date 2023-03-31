#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int t , n , cnt = 0;
    ll sum = 0;
    cin >> n >> t ;
    vector <int> a(n) ;
    rep(i , 0 , n)
    {
        cin >> a[i] ;
    }
    int l = 0 , r = 0 ;
    while(l < n)
    {
        while(sum + a[r]<= t && r < n)
        {
            sum += a[r] ;
            r ++ ;
        }
        cnt = max(cnt , r - l) ;
        sum -= a[l] ;
        l ++ ;
    }
    cout << cnt ;
}
