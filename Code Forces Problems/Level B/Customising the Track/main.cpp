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

void GO() {
    ll n, sum = 0, ans = 0;
    cin >> n;
    vector<ll> tracks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tracks[i];
        sum += tracks[i];
    }
    ll spare = sum % n;
    for (int i = 0; i < n; ++i) {
        tracks[i] = sum / n;
        if (spare > 0) tracks[i]++, spare--;
    }
    vector<ll> suffix(n + 1);
    for (int i = n - 1; i >= 0; --i) suffix[i] += suffix[i + 1] + tracks[i];
    for (int i = 0; i < n; ++i) ans += abs((n - i - 1) * tracks[i] - suffix[i + 1]);
    cout << ans << el;
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
