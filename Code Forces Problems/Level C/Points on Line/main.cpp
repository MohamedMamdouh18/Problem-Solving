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
    ll n, d, ans = 0;
    cin >> n >> d;
    vector<ll> num(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    for (int i = 0; i < n - 2; ++i) {
        ll index = (upper_bound(num.begin() + i + 1, num.end(), d + num[i]) - num.begin()) - 1;
        ll x = index - i;
        ans += x * (x - 1) / 2;
    }
    cout << ans;
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
