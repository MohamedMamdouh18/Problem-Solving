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
int occ[26];

void solve() {
    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;
    if (n - k == 0) {
        cout << "";
        return;
    }

    char ans[n - k];
    int removes = k ;

    for (char i: s) occ[i - 'a']++;
    int i = 0;
    while (removes) {
        while (occ[i] == 0) i++;
        int remain = occ[i];
        occ[i] = (occ[i] > removes) ? (occ[i] - removes) : 0;
        removes = (remain > removes) ? 0 : (removes - remain);
    }

    i = n - k - 1;
    for (int j = s.size() - 1; j >= 0; --j) {
        if (occ[s[j] - 'a'] > 0) {
            ans[i] = s[j];
            i--;
            occ[s[j] - 'a']--;
        }
    }
    for (int j = 0; j < n - k; ++j) cout << ans[j];
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
