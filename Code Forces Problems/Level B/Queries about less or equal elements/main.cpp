#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define fi first
#define srt(a)     (sort(a.begin() , a.end()))
#define pi pair<int,int>
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
int main()
{
    IOS
    int n , m ;
    cin >> n >> m ;
    vector<ll> a(n) ;
    vector<pi> b(m) ;
    vector<int> ans(m) ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] ;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].fi ;
        b[i].se = i ;
    }
    srt(a) ;
    srt(b) ;
    int l = 0 ;
    for(int r = 0 ; r < b.size() ; r ++)
    {
        while(b[r].fi >= a[l] && l < a.size()) l ++ ;
        ans[b[r].se] = l ;
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << " " ;
    }
}
