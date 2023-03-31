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

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

ll lcm(ll a, ll b) {
    return (a * b / (gcd(a, b)));
}

void GO() {
    string s, t;
    cin >> s >> t;
    if (s.size() < t.size()) swap(s, t);
    int _lcm = lcm(s.size(), t.size());
    int sCopy = _lcm / s.size(), tCopy = _lcm / t.size();
    int sptr = 0, tptr = 0, times = 0;
    while (times != sCopy) {
        if (s[sptr] != t[tptr]) {
            cout << -1 << el;
            return;
        }
        sptr = (sptr + 1) % s.size();
        tptr = (tptr + 1) % t.size();
        if (sptr == 0) times++;
    }
    for (int i = 0; i < sCopy; ++i) {
        cout << s ;
    }
    cout << el ;
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
