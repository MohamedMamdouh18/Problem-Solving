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
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = LONG_LONG_MAX;
const double eps = 1e-6;

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

void GREEN() {
    ll n, missing = 0, _gcd = 0, maxi = LONG_LONG_MIN;
    cin >> n;
    vector<ll> sword(n);
    for (int i = 0; i < n; ++i) {
        cin >> sword[i];
        maxi = max(maxi, sword[i]);
    }
    for (int i = 0; i < n; ++i) {
        missing += maxi - sword[i];
        _gcd = gcd(_gcd, maxi - sword[i]);
    }
    cout << missing / _gcd << " " << _gcd;

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
