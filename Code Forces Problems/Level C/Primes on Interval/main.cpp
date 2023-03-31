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

bool divisors[1000001];
ll prefixPrime[1000001];

void sieve() {
    for (ll i = 2; i <= 1000001; i++) {
        if (!divisors[i]) {
            for (ll j = i * i; j <= 1000001; j += i) divisors[j] = true;
        }
    }
    for (ll i = 2; i <= 1000001; ++i) prefixPrime[i] += prefixPrime[i - 1] + (!divisors[i]);
}

bool good(ll i, ll a, ll b, ll k) {
    bool flag = true;
    for (ll x = a; x <= b - i + 1; ++x) {
        if (prefixPrime[x + i - 1] - prefixPrime[x - 1] < k) {
            flag = false;
            break;
        }
    }
    return flag;
}

void GREEN() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll maxi = b - a + 1;
    ll l = 1, r = maxi;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (good(mid, a, b, k)) r = mid;
        else l = mid;
    }
    if (r == maxi) {
        bool flag = true;
        for (ll x = a; x <= b - r + 1; ++x) {
            if (prefixPrime[x + r - 1] - prefixPrime[x - 1] < k) {
                flag = false;
                break;
            }
        }
        if (flag) cout << r;
        else cout << -1;
    } else cout << r;
}

int main() {
    IOS
    PREC
    sieve();
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
