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
    int bits[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> bits[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (bits[i][j]) {
                if (!(j < m - 1 && i < n - 1 && bits[i][j + 1] && bits[i + 1][j] && bits[i + 1][j + 1])
                    && !(j > 0 && i < n - 1 && bits[i][j - 1] && bits[i + 1][j] && bits[i + 1][j - 1])
                    && !(j < m - 1 && i > 0 && bits[i][j + 1] && bits[i - 1][j] && bits[i - 1][j + 1])
                    && !(j > 0 && i > 0 && bits[i][j - 1] && bits[i - 1][j] && bits[i - 1][j - 1])) {
                    cout << -1;
                    return;
                }
            }
        }
    }
    int ans = 0;
    vector<pair<int, int>> op;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (bits[i][j]) {
                if ((bits[i][j + 1] && bits[i + 1][j] && bits[i + 1][j + 1])) {
                    ans++;
                    op.emplace_back(i + 1, j + 1);
                }

            }
        }
    }
    cout << ans << el;
    for (int i = 0; i < op.size(); ++i) cout << op[i].fi << " " << op[i].se << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
