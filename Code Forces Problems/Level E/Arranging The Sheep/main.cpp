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
ll n, pos, avg, ans, r, l,cnt;

bool cmp(ll a, ll b) {
    return abs(a - avg) < abs(b - avg);
}

void GREEN() {
    ans = 0, avg = 0, l = 0, r = 0 , cnt = 0;
    char c;
    cin >> n;
    vector<ll> sheep;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == '*') {
            sheep.pb(i);
            avg += i + 1;
            cnt ++ ;
        }
    }
    if (sheep.empty()) {
        cout << 0 << el;
        return;
    }
    avg = pos = sheep[cnt / 2] ;
    sort(all(sheep), cmp);
    for (int i: sheep) {
        if (i < pos) {
            ans += (pos - i - 1 - r);
            r++;
        } else if (i > pos) {
            ans += (i - pos - 1 - l);
            l++;
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
