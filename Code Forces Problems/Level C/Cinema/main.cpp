#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n ,x,m;
    cin >> n ;
    unordered_map<int,int> scientist ;
    for (int i = 0; i < n; ++i) {
        cin >> x ;
        scientist[x] ++ ;
    }
    cin >> m ;
    vector<pair<int,int>> movies(m) ;
    vector<pair<ll,int>> rating(m) ;
    for (int i = 0; i < m; ++i) cin >> movies[i].fi ;
    for (int i = 0; i < m; ++i) cin >> movies[i].se ;
    for (int i = 0; i < m; ++i) {
        rating[i].fi = scientist[movies[i].fi] * 10 + scientist[movies[i].se] ;
        rating[i].se = i+1 ;
    }
    sort(rating.begin() , rating.end()) ;
    cout << rating[rating.size()-1].se ;
}
