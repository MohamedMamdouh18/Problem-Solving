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
const ll mod = 1e9 + 7, N = 2 * 1e5 + 2;
int freq[N];
vector<pair<int, int> > rep;
int n, t, x;
 
bool good(int repetitions) {
    int buf = 0;
    for (int i = 0; i < rep.size(); ++i) {
        int cur = rep[i].fi / repetitions;
        if (cur == 0) break;
        buf += cur;
    }
    return buf >= t;
}
 
void GREEN() {
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        freq[x]++;
    }
    for (int i = 1; i < N; ++i) if (freq[i]) rep.pb({freq[i], i});
    sort(rep.rbegin(), rep.rend());
    int l = 0, r = N;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (good(mid)) l = mid;
        else r = mid;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < rep.size(); ++i) {
        if (rep[i].fi / l == 0) break;
        ans.pb({rep[i].se, rep[i].fi / l});
    }
    int put = 0;
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].se; ++j) {
            cout << ans[i].fi << " ";
            put++;
            if (put == t) return;
        }
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
