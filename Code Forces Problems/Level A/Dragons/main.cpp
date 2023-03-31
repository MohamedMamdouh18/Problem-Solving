#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define pb push_back
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define minv(a)      (*min_element((a).begin(), (a).end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int s , n ;
    cin >> s >> n ;
    vector <pair<int , int>> dr(n) ;
    rep(i , 0 , n)
    {
        cin >> dr[i].first >> dr[i].second ;
    }
    srt(dr) ;
    rep(i , 0 , n)
    {
        if(s > dr[i].first)
        {
            s += dr[i].second ;
        }
        else
        {
            cout << "NO" ;
            return 0 ;
        }
    }
    cout << "YES" ;
}
