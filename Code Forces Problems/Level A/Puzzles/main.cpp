#include <bits/stdc++.h>
using namespace std ;

#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int m , n , mine = 1e9;
    cin >> m >> n ;
    vector <int> a(n) ;
    rep(i , 0 , n)
    {
        cin >> a[i] ;
    }
    srt(a) ;
    rep(i , 0 , n - m + 1)
    {
        if(a[i + m - 1] - a[i] < mine)
        {
            mine = a[i + m - 1] - a[i] ;
        }
    }
    cout << mine ;


}
