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
int freq[N];
 
vector<ll> factorize(ll n) {
    vector<ll> fact;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.pb(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) fact.pb(n);
    return fact;
}
 
void GREEN() {
    ll n;
    cin >> n;
    if(n == 1){
        cout << 1 ;
        return;
    }
    auto factor = factorize(n);
    cout << ((factor.size() == 1) ? factor[0] : 1) ;
}
 
int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
