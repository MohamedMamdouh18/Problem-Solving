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
const ll mod = 1e9 + 7 , N =200020;
ll fact[N], invfact[N];

ll mul(ll x, ll y) {
    return ((x % mod) * (y % mod)) % mod;
}

ll add(ll x, ll y) {
    return ((((x % mod) + (y % mod)) % mod) + mod) % mod;
}

ll fp(ll base, ll power) {
    if (power == 0) return 1;
    ll res = fp(base, (power >> 1));
    res = (res * res) % mod;
    if (power & 1) res = (res * base) % mod;
    return res;
}

void init() {
    fact[0] = 1, invfact[0] = 1;
    for (ll i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
        invfact[i] = fp(fact[i], mod - 2);
    }
}

ll ncr(ll n, ll r) {
    ll m = mul(fact[n], invfact[n - r]);
    m = mul(m, invfact[r]);
    return m;
}

void GREEN() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> num(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    ll ans = 0;
    sort(all(num));
    ll r = m - 1, last = -1;
    for (ll l = 0; l < n - (m - 1); ++l) {
        while (r < n - 1 && num[r + 1] - num[l] < k + 1) r++;
        if (num[r] - num[l] < k + 1 && r - l + 1 > m - 1) {
            ans = add(ans, ncr(r - l + 1, m));
            if (last - l + 1 >= m) ans = add(ans, -ncr(last - l + 1, m));
            last = r;
        }
    }
    cout << ans << el;

}

int main() {
    IOS
    PREC
    init();
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
