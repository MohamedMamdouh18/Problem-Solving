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
    ll a, b, k, ans = 0;
    cin >> a >> b >> k;
    map<ll, ll> count;
    vector<pair<ll, ll>> pair(k);
    for (int i = 0; i < k; ++i) {
        cin >> pair[i].fi;
        count[pair[i].fi]++;
    }
    for (int i = 0; i < k; ++i) {
        cin >> pair[i].se;
        pair[i].se += a;
        count[pair[i].se]++;
    }
    for (int i = 0; i < k; ++i) ans += (k - count[pair[i].fi] - count[pair[i].se] + 1);
    cout << ans / 2 << el;

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
