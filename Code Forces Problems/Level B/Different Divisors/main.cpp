#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

bool divisor[1000001] ;
vector<ll> primes ;

void sieve(){
    for (ll i = 2; i < 1000001 ; ++i) {
        if(!divisor[i]){
            primes.pb(i) ;
            for (ll j = i * i; j < 1000001; j += i) divisor[j] = true ;
        }
    }
}

void GREEN() {
    ll d , ans = 1 ;
    cin >> d ;
    ans *= *lower_bound(all(primes) , (ans + d)) ;
    ans *= *lower_bound(all(primes) , (ans + d)) ;
    cout << ans << el;

}

int main() {
    IOS
    PREC
    sieve() ;
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
