#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = LONG_LONG_MAX;
const double eps = 1e-6;
vector<ll> section;
ll n, range, k;

bool good(ll num) {
    ll have = 0, used = 0;
    for (int i = 0; i <= range; ++i) have += section[i];
    vector<ll> pos(n);
    for (int i = 0; i < n; ++i) {
        if (i >= range + 1) have -= (section[i - range - 1] + pos[i - range - 1]);
        if (i + range < n && i > 0) have += section[i + range] + pos[i + range];
        if (have >= num) continue;

        ll cur = (num - have);
        used += cur;
        if (used > k) return false;
        if (i + range < n) pos[i + range] += cur;
        else pos[i] += cur;
        have += cur;
    }
    return used <= k;
}

void GREEN() {
    cin >> n >> range >> k;
    if (range == n) range--;
    section.resize(n);
    for (int i = 0; i < n; ++i) cin >> section[i];
    ll l = 0, r = INF ;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (good(mid)) l = mid;
        else r = mid;
    }
    cout << l;

}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
