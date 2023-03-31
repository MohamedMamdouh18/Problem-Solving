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
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() > s2.size() || s1[0] != s2[0]) {
        cout << "NO" << el;
        return;
    }
    int j = 0, i, cnt1 = 1, cnt2 = 1;;
    for (i = 0; i < s1.size(); ++i, ++j) {
        if (s1[i] != s2[j] || cnt2 < cnt1) {
            cout << "NO" << el;
            return;
        }
        cnt1 = 1, cnt2 = 1;
        while (i < s1.size() && s1[i] == s1[i + 1]) cnt1++, i++;
        while (j < s2.size() && s2[j] == s2[j + 1]) cnt2++, j++;
    }
    if (cnt2 < cnt1) cout << "NO" << el;
    else {
        if (s2.size() > s1.size()) {
            for (int k = s2.size() - 1; k >= j; --k) {
                if (s2[k] != s1[i]){
                    cout << "NO" << el;
                    return;
                }
            }
            cout << "YES" << el;
        } else cout << "YES" << el;
    }
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
