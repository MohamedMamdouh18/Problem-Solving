#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e5 + 1;
vector<ll> recipe ,have ;
ll n , k ;

bool good(ll cnt){
    ll cost = 0 ;
    for (int i = 0; i < n; ++i) {
        ll current = have[i] / recipe[i];
        if (current >= cnt) continue;
        ll rem = recipe[i] - (have[i] - (current * recipe[i]));
        cost += rem;
        current++;
        if (current >= cnt) continue;
        cost += (recipe[i] * (cnt - current)) ;
        if(cost > k) return false ;
    }
    return cost <= k ;
}

void GREEN() {
    cin >> n >> k ;
    recipe.resize(n) , have.resize(n) ;
    for (int i = 0; i < n; ++i) cin >> recipe[i] ;
    for (int i = 0; i < n; ++i) cin >> have[i] ;
    ll l = 0 , r = 2 * 1e9 + 1;
    while (l+1 < r){
        ll mid = (l+r) / 2 ;
        if(good(mid)) l = mid ;
        else r = mid ;
    }
    cout << l ;
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
