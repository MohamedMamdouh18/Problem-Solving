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
const ll mod = 1073741824;
ll freq[1000001];

ll getDivisors(ll n) {
    ll cnt = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i) cnt++;
        }
    }
    return cnt % mod;
}

ll add(ll x, ll y) {
    return ((((x % mod) + (y % mod)) % mod) + mod) % mod;
}

ll mul(ll x, ll y) {
    return ((x % mod) * (y % mod)) % mod;
}

void GO() {
    ll a, b, c, sum = 0;
    cin >> a >> b >> c;
    for (ll i = 1; i <= a; ++i) {
        for (ll j = 1; j <= b; ++j) {
            for (ll k = 1; k <= c; ++k) {
                ll num = mul(i, mul(j, k));
                if (freq[num] == 0) freq[num] = getDivisors(num);
                sum = add(sum, freq[num]);
            }
        }
    }
    cout << sum;
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
