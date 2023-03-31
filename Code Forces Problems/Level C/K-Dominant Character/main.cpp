#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e6;

void GREEN() {
    string s;
    cin >> s;
    map<char, int> pos;
    map<char, int> space;
    for (int i = 'a'; i <= 'z'; ++i) pos[i] = -1;
    for (int i = 0; i < s.size(); ++i) {
        space[s[i]] = max(space[s[i]], i - pos[s[i]]);
        pos[s[i]] = i;
    }
    for (int i = 'a'; i <= 'z'; ++i) space[i] = max(space[i], (int) s.size() - pos[i]);
    int ans = INT_MAX;
    for (int i = 'a'; i <= 'z'; ++i) ans = min(ans, space[i]);

    cout << ans;
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
