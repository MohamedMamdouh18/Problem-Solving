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
const ll mod = 1e9 + 7, N = 2e7 + 25;
bool prime[N];
int p[N], prime_count[N];
vector<ll> series;

void sieve() {
    prime[0] = prime[1] = true ;
    for (ll i = 2; i < N; ++i) {
        if (!prime[i]) {
            prime_count[i] = 1;
            for (ll j = i * i; j < N; j += i) {
                prime[j] = true;
                p[j] = j / i;
                if (j / i == i) p[j] = 1;
            }
        }
    }
    for (ll i = 2; i < N; ++i) {
        if (!prime[p[i]]) {
            series.push_back(i);
        }
    }
}

void GREEN() {
    ll k;
    cin >> k;
    cout << series[k - 1] << el;
}

int main() {
    IOS
    PREC
    sieve();
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
