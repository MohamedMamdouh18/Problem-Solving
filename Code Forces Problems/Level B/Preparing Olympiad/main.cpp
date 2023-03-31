#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    ll n , l , r , x , ans = 0;
    cin >> n >> l >> r >> x ;
    vector<ll> problem(n) ;
    for (int i = 0; i < n; ++i) cin >> problem[i] ;
    for (int mask = 0; mask < (1 << n); ++mask) {
        ll sum = 0 , mini = INT_MAX , maxi = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if(mask & (1 << i)){
                sum += problem[i] ;
                maxi = max(maxi , problem[i]) ;
                mini = min(mini , problem[i]) ;
            }
        }
        if(sum >= l && sum <= r && maxi - mini >= x) ans ++ ;
    }
    cout << ans ;
}

int main() {
    IOS
    PREC

    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
