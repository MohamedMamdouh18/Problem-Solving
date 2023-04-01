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
const int mod = 1e9 + 7, N = 1e5 + 50, M = 23, INF = INT_MAX;
const double eps = 1e-6;

int base1 = 61, base2 = 67;
int pw[N], inv[N], pw2[N], inv2[N];

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

struct h {

    int pref[N], pref2[N];

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
};

void GREEN() {
    string s;
    while (cin >> s) {
        bool valid = false;
        auto h1 = new h();
        auto h2 = new h();
        h1->generate_hash(s);
        reverse(all(s));
        h2->generate_hash(s);
        reverse(all(s));

        if (h1->getHash(1, (int) s.size() / 2) == h2->getHash(1, (int) s.size() / 2)) {
            cout << s << el;
            continue;
        }

        for (int i = (int) s.size() / 2 - 1; i < (int) s.size() - 1; ++i) {
            auto hash1 = h1->getHash(i - ((int) s.size() - i) + 2, i + 1);
            auto hash2 = h2->getHash(1, ((int) s.size() - i));
            if (hash1 == hash2) {
                cout << s;
                for (int j = i - ((int) s.size() - i); j >= 0; --j) cout << s[j];
                cout << el;
                valid = true;
                break;
            }

            hash1 = h1->getHash(i - ((int) s.size() - i - 2) + 1, i + 1);
            hash2 = h2->getHash(1, ((int) s.size() - i) - 1);
            if (hash1 == hash2) {
                cout << s;
                for (int j = i - ((int) s.size() - i ) + 1; j >= 0; --j) cout << s[j];
                cout << el;
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << s;
            reverse(all(s));
            for (int i = 1; i < (int) s.size(); ++i) cout << s[i];
            cout << el;
        }
    }
}

int main() {
    IOS
    PREC
    pre();
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
