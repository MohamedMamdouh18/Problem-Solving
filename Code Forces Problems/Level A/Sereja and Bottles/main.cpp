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
vector<vector<int>> adj;

void GREEN() {
    int n, a, b, ans = 0;
    cin >> n;
    vector<int> need(1001);
    vector<bool> have(1001, false);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (need[b]) need[b] = 0;
        if (!have[a]) need[a]++;
        have[b] = true;
    }
    for (int i: need) ans += i;
    cout << ans;
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
