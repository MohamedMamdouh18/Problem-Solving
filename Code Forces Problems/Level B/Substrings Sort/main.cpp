#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define mp make_pair
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)



int main() {
    IOS
    int n ;
    cin >> n ;
    vector<string> a(n) ;
    vector<pair<int,int>> ss ;
    rep(i , 0 , n)
    {
        cin >> a[i] ;
        ss.pb(mp(a[i].size() , i)) ;
    }
    srt(ss) ;
    rep(i , 1 , n)
    {
        if(a[ss[i].second].find(a[ss[i - 1].second]) == a[ss[i].second].npos)
        {
            cout << "NO" ;
            return 0 ;
        }
    }
    cout <<"YES" << endl ;
    rep(i , 0 , n)
    {
        cout <<a[ss[i].second] << endl ;
    }



}
