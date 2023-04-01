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

void solve() {
    ll n, u, q;
    cin >> n >> u;
    vector<ll> prefix(n+1);
    for (int i = 0; i < u; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        prefix[l] += x;
        prefix[++r] -= x;
    }
    for (int i = 1; i < n + 2; ++i) prefix[i] += prefix[i - 1];
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int j;
        cin >> j;
        cout << prefix[j] << el;
    }
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
