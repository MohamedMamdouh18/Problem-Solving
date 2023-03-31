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
const double eps = 1e-6;

int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

void GREEN() {
    int n;
    cin >> n;
    vector<int> ans;
    int cur = n * 2 + 2;
    ans.pb(cur);
    n--;
    while (n) {
        bool flag = false;
        cur++;
        for (int i: ans) {
            if ((cur % i) == 0 || gcd(cur, i) == 1) flag = true;
        }
        if (flag) continue;
        n--, ans.pb(cur);
    }
    for (int i: ans) cout << i << " ";
    cout << el;
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
