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

void GO() {
    ll n, k, ans, mult = 1;
    cin >> n >> k;
    vector<ll> num(n);
    for (ll i = 0; i < n; ++i) cin >> num[i];
    sort(all(num));
    ans = num[n / 2];
    for (ll i = n / 2; i < n - 1; ++i) {
        if ((num[i + 1] - num[i]) * mult <= k) {
            ans = num[i + 1];
            k -= ((num[i + 1] - num[i]) * mult);
            mult++;
        } else break;
    }
    cout << ans + floor((double )k / mult);
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
