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
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n , k , num = 0;
    cin >> n >> k ;
    vpi a(n) ;
    rep(i , 0 , n)
    {
        cin >>a[i].first >> a[i].second ;
        a[i].first = -a[i].first ;
    }
    srt(a) ;
    int fi = a[k-1].first , sec = a[k-1].second ;
    rep(i , 0 , n)
    {
        if(fi == a[i].first && sec == a[i].second )
        {
            num ++ ;
        }
    }
    cout << num ;

}
