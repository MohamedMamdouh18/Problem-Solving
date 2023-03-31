#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    ll n , r , l , sum = 0 , ans = 0;
    cin >> n >> r >> l ;
    l *= n ;
    vector<pair<ll,ll>> exam(n) ;
    for (int i = 0; i < n; ++i) {
        cin >> exam[i].se >> exam[i].fi ;
        sum += exam[i].se ;
    }
    sort(all(exam)) ;
    int i = 0 ;
    while (sum < l){
        if((l-sum) > (r-exam[i].se)){
            ans += (exam[i].fi * (r -exam[i].se));
            sum += (r -exam[i].se) ;
            i ++ ;
        }else{
            ans += (exam[i].fi * (l - sum));
            break;
        }
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
