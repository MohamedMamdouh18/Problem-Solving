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
const ll mod = 1e9 + 7, N = 1050, INF = LONG_LONG_MAX;
int base1 = 29, base2 = 31;
ll pw[N], inv[N], pref[N], pw2[N], inv2[N], pref2[N];

ll add(ll a, ll b) {
    return (a + b) % mod;
}

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll fp(ll base, ll power) {
    if (power == 0) return 1ll;
    ll res = fp(base, power >> 1);
    res = mul(res, res);
    if (power & 1) res = mul(res, base);
    return res;
}

void pre() {
    pw[0] = inv[0] = 1;
    pw2[0] = inv2[0] = 1;
    ll mul_inv = fp(base1, mod - 2);
    ll mul_inv2 = fp(base2, mod - 2);
    for (int i = 1; i < N; ++i) {
        pw[i] = mul(base1, pw[i - 1]);
        pw2[i] = mul(base2, pw2[i - 1]);
        inv[i] = mul(inv[i - 1], mul_inv);
        inv2[i] = mul(inv2[i - 1], mul_inv2);
    }
}

pair<ll, ll> get_Hash(int l, int r) {
    ll hash1 = mul(add(pref[r], mod - pref[l - 1]), inv[l]);
    ll hash2 = mul(add(pref2[r], mod - pref2[l - 1]), inv2[l]);
    return {hash1, hash2};
}

void generate_Hash(string &s) {
    for (int i = 1; i <= s.size(); ++i) {
        int idx = s[i - 1] - 'A' + 1;
        pref[i] = mul(idx, pw[i]);
        pref2[i] = mul(idx, pw2[i]);
        pref[i] = add(pref[i], pref[i - 1]);
        pref2[i] = add(pref2[i], pref2[i - 1]);
    }
}


void GREEN() {
    string s;
    while (getline(cin, s)) {
        string tmp;
        for (char i: s) {
            if (i != ' ')
                tmp.pb(i);
        }
        generate_Hash(tmp);
        int len = 1;
        while (len < tmp.size()) {
            map<pair<ll, ll>, int> freq;
            int maxi = -1;
            for (int i = 1; i <= tmp.size() - len + 1; ++i) {
                auto hash = get_Hash(i, i + len - 1);
                freq[hash]++;
                if (freq[hash] > maxi)
                    maxi = freq[hash];
            }
            if (maxi > 1)
                cout << maxi << el;
            else
                break;
            len++;
        }
        if(len > 1)
            cout << el;
    }
}

int main() {
    PREC
    IOS
    pre();
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
