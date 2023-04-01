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
const int mod = 1e9 + 7, N = 1e6 + 50, M = 23, INF = INT_MAX;
const double eps = 1e-6;

int fail[N];

void KMP(string &s) {
    for (int i = 1; i < (int) s.size(); ++i) {
        int j = fail[i - 1];
        while (j > 0 && s[i] != s[j])
            j = fail[j - 1];
        fail[i] = (s[i] == s[j]) ? j + 1 : 0;
    }
}

void GREEN() {
    string s, pat;
    cin >> s >> pat;
    vector<int> ans;
    KMP(pat);
    int j = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        while (j > 0 && s[i] != pat[j])
            j = fail[j - 1];
        if (s[i] == pat[j]) j++;
        if (j == pat.size()) {
            ans.pb(i - j + 2);
            j = fail[j - 1];
        }
    }
    if (ans.empty()) cout << "Not Found" << el;
    else {
        cout << ans.size() << el;
        for (int i = 0; i < (int) ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << el;
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
