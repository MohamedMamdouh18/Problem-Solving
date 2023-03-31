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

int divisor[1000001];
set<ll> tprime;

void sieve() {
    for (ll i = 2; i <= 1000000; i++) {
        if (!divisor[i])
            for (ll j = i * i; j <= 1000000; j += i)
                divisor[j]++;
    }
    for (ll i = 2; i <= 1000000; ++i) {
        if (divisor[i] == 0) tprime.insert(i * i);
    }
}

void GO() {
    ll n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (tprime.count(x)) cout << "YES" << el;
        else cout << "NO" << el;
    }
}

int main() {
    IOS
    PREC
    sieve();

    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
