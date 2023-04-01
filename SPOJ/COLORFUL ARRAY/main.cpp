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
const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;

void GREEN() {
    int n, m;
    cin >> n >> m;
    set<int> color;
    for (int i = 1; i <= n; ++i) color.insert(i);
    vector<pair<pair<int, int>, int>> query(m);
    vector<int> ans(n + 1);
    for (int i = 0; i < m; ++i)
        cin >> query[i].fi.fi >> query[i].fi.se >> query[i].se;
    for (int i = m - 1; i >= 0; --i) {
        int l = query[i].fi.fi,
                r = query[i].fi.se, c = query[i].se;
        while (true) {
            auto ptr = color.lower_bound(l);
            if (ptr == color.end() || *ptr > r) break;
            ans[*ptr] = c, l++;
            color.erase(ptr) ;
        }
        if (color.empty()) break;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << el;
    }
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
