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
ll n, m, k;

ll count(ll mid) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += min(m, ((mid - 1) / i));
    }
    return cnt;
}

void solve() {
    cin >> n >> m >> k;

    ll l = 1, r = n * m;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll cnt = count(mid) + 1;
        if (cnt <= k) l = mid + 1;
        else if (cnt > k) r = mid - 1;
    }
    cout << l - 1;
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
