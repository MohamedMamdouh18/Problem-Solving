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
    int n, k, ans = 0;
    cin >> n >> k;
    string s;
    vector<int> prefix(n + 1);
    cin >> s;
    for (int i = 1; i < n + 1; ++i) prefix[i] = prefix[i - 1] + (s[i - 1] - '0');
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            int right, left;

            if (i <= k)left = prefix[i] - prefix[0];
            else left = prefix[i] - prefix[i - k];

            if (i + k + 1 >= prefix.size()) right = prefix[prefix.size() - 1] - prefix[i + 1];
            else right = prefix[i + k + 1] - prefix[i + 1];

            if (left == 0 && right == 0) {
                ans++;
                i += k ;
            }
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
        solve();
    }
}
