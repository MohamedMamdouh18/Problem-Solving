#include <bits/stdc++.h>
using namespace std ;

#define srt(a)     (sort(a.begin() , a.end()))
#define rev(a)  (reverse(a.begin() , a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n ;
    cin >> n ;
    vector <int> a(n) ;
    rep(i , 0 , n)
    {
        cin >> a[i] ;
    }
    vector<int> ac(n+1) ;
    srt(a) ;
    rev(a) ;
    int sume = sum(a) ;

    rep(i , 1 , n+1)
    {
        ac[i] += ac[i-1] + a[i-1] ;
        if(ac[i] > sume / 2)
        {
            cout << i ;
            return 0 ;
        }
    }
}
