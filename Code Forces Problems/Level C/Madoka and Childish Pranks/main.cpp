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
    int n, m;
    cin >> n >> m;
    char paint[n][m];
    vector<pair<pair<int, int>, pair<int, int>>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> paint[i][j];
    }
    if (paint[0][0] == '1') {
        cout << -1 << el;
        return;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i > 0 && paint[i][j] == '1')
                ans.pb({{i, j + 1},
                        {i + 1, j + 1}});
            if (i == 0 && paint[i][j] == '1')
                ans.pb({{i + 1, j},
                        {i + 1, j + 1}});
        }
    }
    cout << ans.size() << el;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].fi.fi << " " << ans[i].fi.se << " " << ans[i].se.fi << " " << ans[i].se.se << el;

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
