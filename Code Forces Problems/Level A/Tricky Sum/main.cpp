#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
vector<ll> powers ;

void calc_powers(){
    ll i = 1 ;
    powers.pb(1) ;
    while(i <= 10e9){
        i *= 2 ;
        powers.pb(i) ;
    }
}

void solve() {
    ll n , sum = 0 , i = 0 , last = 0;
    cin >> n ;
    for (; i < powers.size(); ++i) {
        if(n < powers[i]) break;
        sum = sum + ((powers[i] * (powers[i] + 1)) / 2) - ((last * (last + 1)) / 2) - 2 * powers[i];
        last = powers[i] ;
    }
    i -- ;
    sum = sum + (n * (n + 1)) / 2 - (last * (last + 1)) / 2 ;
    cout << sum << el ;

}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    calc_powers() ;
    while (tc--) {
        solve();
    }
}
