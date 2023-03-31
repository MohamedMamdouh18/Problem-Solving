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
const ll mod = 1e9 + 7, N = 1e6;

void GREEN() {
    int n, m, x, ans = 0, end;
    cin >> n >> m;
    vector<int> mods(m);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        mods[x % m]++;
    }
    if (mods[0] != 0) ans++;
    if (!(m & 1)) {
        end = m / 2;
        if (mods[m / 2] != 0)ans++;
    } else end = (m + 1) / 2;
    for (int i = 1; i < end; ++i) {
        if (mods[i] == 0 || mods[m - i] == 0) ans += max(mods[i], mods[m - i]);
        else if (mods[i] == mods[m - i] || abs(mods[i] - mods[m - i]) == 1) ans++;
        else {
            int remove = min(mods[i], mods[m - i]);
            ans += max(mods[i], mods[m - i]) - remove;
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
