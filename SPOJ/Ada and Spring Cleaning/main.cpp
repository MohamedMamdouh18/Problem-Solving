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
const int mod = 1e9 + 7, N = 1e6 + 50, M = 23, INF = INT_MAX;
const double eps = 1e-6;

int base1 = 29, base2 = 31;

int pref[N], pref2[N], pw[N], inv[N], pw2[N], inv2[N];

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int fp(int base, int power) {
    if (power == 0) return 1;
    int temp = fp(base, (power >> 1));
    temp = mul(temp, temp);
    if (power & 1) temp = mul(temp, base);
    return temp;
}

void pre() {
    pw[0] = inv[0] = 1;
    pw2[0] = inv2[0] = 1;

    int mul_inv = fp(base1, mod - 2);
    int mul_inv2 = fp(base2, mod - 2);
    for (int i = 1; i < N; i++) {
        pw[i] = mul(base1, pw[i - 1]);
        inv[i] = mul(inv[i - 1], mul_inv);

        pw2[i] = mul(base2, pw2[i - 1]);
        inv2[i] = mul(inv2[i - 1], mul_inv2);
    }
}

void generate_hash(string &s) {
    for (int i = 1; i <= s.size(); i++) {
        int idx = s[i - 1] - 'a' + 1;
        pref[i] = mul(idx, pw[i]);
        pref[i] = add(pref[i], pref[i - 1]);

        pref2[i] = mul(idx, pw2[i]);
        pref2[i] = add(pref2[i], pref2[i - 1]);
    }
}

//l & r are 1_indexed
pair<int, int> getHash(int l, int r) {
    int hash1 = mul(add(pref[r], mod - pref[l - 1]), inv[l]);
    int hash2 = mul(add(pref2[r], mod - pref2[l - 1]), inv2[l]);

    return {hash1, hash2};
}

void GREEN() {
    string s;
    int n, k, ans = 0;
    cin >> n >> k;
    cin >> s;
    generate_hash(s);
    map<pair<int, int>, bool> exist;
    for (int i = 1; i <= (int) s.size() - k + 1; ++i) {
        auto hash = getHash(i, i + k - 1);
        if (!exist.count(hash)) {
            ans++;
            exist[hash] = true;
        }
    }
    cout << ans << el;
}

int main() {
    IOS
    PREC
    pre();
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
