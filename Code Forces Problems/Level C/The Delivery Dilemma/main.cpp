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
    ll n, ans = 0, petya = 0, delivery = 0;
    cin >> n;
    vector<pair<ll, ll>> time(n);
    for (int i = 0; i < n; ++i) cin >> time[i].fi;
    for (int i = 0; i < n; ++i) cin >> time[i].se;

    sort(time.rbegin(), time.rend());
    for (int i = 0; i < n; ++i) {
        if (petya + time[i].se < time[i].fi) petya += time[i].se;
        else delivery = max(delivery, time[i].fi);
    }
    cout << max(petya, delivery) << el;
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
