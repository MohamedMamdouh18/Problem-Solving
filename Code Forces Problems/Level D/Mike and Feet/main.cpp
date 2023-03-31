#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    ll n, last;
    cin >> n;
    stack<ll> monotonic;
    vector<ll> nums(n), previous(n), after(n), ans(n + 1);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    for (int i = 0; i < n; ++i) {
        while (!monotonic.empty() && nums[monotonic.top()] >= nums[i]) monotonic.pop();
        if (monotonic.empty()) previous[i] = -1;
        else previous[i] = monotonic.top();
        monotonic.push(i);
    }
    monotonic = stack<ll>();
    for (int i = n - 1; i >= 0; --i) {
        while (!monotonic.empty() && nums[monotonic.top()] >= nums[i]) monotonic.pop();
        if (monotonic.empty()) after[i] = n;
        else after[i] = monotonic.top();
        monotonic.push(i);
    }
    for (int i = 0; i < n; ++i) {
        ll sz = after[i] - previous[i] - 1;
        ans[sz] = max(ans[sz], nums[i]);
    }
    for (int i = n-1; i >= 0; --i) ans[i] = max(ans[i + 1], ans[i]);

    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}
