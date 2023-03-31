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
ll mod = 100;

ll fp(ll base, ll power) {
    if (power == 0) return 1;
    ll res = fp(base, power / 2);
    res = (res * res) % mod;
    if (power & 1) res = (res * base) % mod;
    return res;
}

void GO() {
    ll n;
    cin >> n ;

    cout << fp((ll) 5, n) << el;
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
