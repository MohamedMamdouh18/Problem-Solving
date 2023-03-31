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
    ll m = 1;
    for (int i = 0; i < r; ++i) m = m * (n - i) / (i + 1);
    return m;
}


void GREEN() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    ll ans = 0;
    sort(all(num));
    int r = 2, last = -1;
    for (int l = 0; l < n - 2; ++l) {
        while (r < n - 1 && num[r + 1] - num[l] < 3) r++;
        if (num[r] - num[l] < 3 && r - l + 1 > 2) {
            ans += ncr(r - l + 1, 3);
            if (last - l + 1 >= 3) ans -= ncr(last - l + 1, 3);
            last = r;
        }
    }
    cout << ans << el;

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
