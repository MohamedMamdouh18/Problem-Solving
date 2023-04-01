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
    ll n, q;
    cin >> n;
    vector<ll> num(n + 1), prefix(n + 2);
    for (int i = 0; i < n; ++i) cin >> num[i];
    for (int i = 1; i < n + 2; ++i) prefix[i] += num[i - 1] + prefix[i - 1];
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r+1] -prefix[l] << el ;
    }
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
