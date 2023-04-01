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

ll ncr(ll n, ll r) {
    ll m1 = 1;
    for (int i = 0; i < r; i++)
        m1 = m1 * (n - i) / (i + 1);
    return m1;
}

void GREEN() {
    ll n, k;
    cin >> n >> k;
    ll r = n - k;
    n = k + r - 1;

    cout << ncr(n, min(r, n - r)) << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
