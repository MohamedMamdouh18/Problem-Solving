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

ll isPrime(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i== 0) return i;
    }
    return -1;
}

void GO() {
    ll n;
    cin >> n;
    ll degree = isPrime(n);
    if (degree == -1) cout << 1 << " " << n - 1 << el;
    else {
        cout << n / degree << " " << n - n / degree << el;
    }

}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GO();
    }
}
