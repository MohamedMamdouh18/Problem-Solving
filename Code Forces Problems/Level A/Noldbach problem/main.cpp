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

bool isPrime(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void GO() {
    int n, k, ans = 0;
    cin >> n >> k;

    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) primes.pb(i);
    }
    for (int i = primes.size() - 1; i >= 0; i--) {
        int current = primes[i] - 1;
        for (int j = 0; j < i - 1; ++j) {
            if (current == primes[j] + primes[j + 1]) ans++;
        }
    }
    if(ans >= k) cout << "YES";
    else cout << "NO";

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
