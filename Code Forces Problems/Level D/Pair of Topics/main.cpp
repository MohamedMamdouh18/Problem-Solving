#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    ll n, ans = 0;
    cin >> n;
    vector<ll> good(n);
    for (int i = 0; i < n; ++i) {
        cin >> good[i];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        good[i] -= x;
    }

    sort(good.begin(), good.end());
    for (int i = 0; i < n; ++i) {
        int num = upper_bound(good.begin() + i + 1, good.end(), -good[i]) - good.begin();
        ans += n - num;
    }
    cout << ans;
}
