#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define s \
 iz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
int freq[100001];

void solve() {
    int n, m, x;
    cin >> n >> m;
    set<int> uniq;
    vector <pair<int, int>> suff(m);
    vector<int> ans(m), num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        freq[num[i]]++;
        uniq.insert(num[i]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> suff[i].fi;
        suff[i].se = i;
    }
    sort(all(suff));
    int l = 1;
    for (int i = 0; i < m; ++i) {
        while (l != suff[i].fi) {
            freq[num[l - 1]]--;
            if (freq[num[l - 1]] == 0) uniq.erase(num[l - 1]);
            l++;
        }
        ans[suff[i].se] = uniq.size();
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << el;
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
