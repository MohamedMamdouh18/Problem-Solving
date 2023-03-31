#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
int freq[100001];

void solve() {
    int n, k, ans = 0, last = 0;
    cin >> n >> k;
    vector<pair<int, int>> prob(n);
    vector<int> index;
    for (int i = 0; i < n; ++i) {
        cin >> prob[i].fi;
        prob[i].se = -(i + 1);
    }
    sort(prob.rbegin(), prob.rend());
    for (int i = 0; i < k; ++i) {
        ans += prob[i].fi;
        index.pb(-prob[i].se);
    }
    sort(all(index));
    cout << ans << el;
    for (int i = 0; i < k; ++i) {
        if (i == k - 1) index[i] = n;
        cout << index[i] - last << " ";
        last = index[i];
    }

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
