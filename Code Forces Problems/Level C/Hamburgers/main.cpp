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
const ll mod = 1e9 + 7, N = 1e5 + 1;
ll recipe[3], have[3], price[3], money;

bool good(ll cnt) {
    ll cost = 0;
    for (int i = 0; i < 3; ++i) {
        if (recipe[i] > 0) {
            ll current = have[i] / recipe[i];
            if (current >= cnt) continue;
            ll rem = recipe[i] - (have[i] - (current * recipe[i]));
            cost += rem * price[i];
            current++;
            if (current >= cnt) continue;
            cost += (recipe[i] * (cnt - current)) * price[i];
        }
    }
    return cost <= money;
}

void GREEN() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'B') recipe[0]++;
        if (s[i] == 'S') recipe[1]++;
        if (s[i] == 'C') recipe[2]++;
    }
    for (int i = 0; i < 3; ++i) cin >> have[i];
    for (int i = 0; i < 3; ++i) cin >> price[i];
    cin >> money;

    ll l = 0, r = 1e12 + 200;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (good(mid)) l = mid;
        else r = mid;
    }

    cout << l;
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
