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

void GO() {
    int n, mini = INT_MAX, ans = 0;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        mini = min(num[i], mini);
    }
    for (int i = 0; i < n; ++i) num[i] -= mini;
    for (int i = 0; i < n; ++i) if (num[i] != 0) ans = gcd(num[i], ans);
    cout << ((ans == 0) ? -1 : ans) << el;
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
