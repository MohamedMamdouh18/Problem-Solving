#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n , d ;
    cin >> n >> d ;
    vector<pair<ll,ll>> a(n) ;
    rep(i , 0 , n)
    {
        cin >> a[i].first >> a[i].second ;
    }
    srt(a) ;
    ll sum = 0 , num = 0;
    int l = 0 , r = 0  ;
    while(l < n)
    {
        while(r < n && a[r].first - a[l].first < d)
        {
            sum += a[r].second ;
            r ++ ;
        }
        num = max(sum , num) ;
        sum -= a[l].second ;
        l ++ ;
    }
    cout << num ;
}
