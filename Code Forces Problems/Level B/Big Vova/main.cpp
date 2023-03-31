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

int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

void GO() {
    int n;
    cin >> n;
    vector<pair<int, bool>> num(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> num[i].fi;
    sort(num.rbegin(), num.rend());
    int _gcd = b[0] = num[0].fi;
    for (int i = 1; i < n; ++i) {
        int maxGCD, put, flag = 0;
        for (int j = 1; j < n; ++j) {
            if (!flag && !num[j].se) {
                flag = 1;
                put = j;
                maxGCD = gcd(_gcd, num[j].fi);
            } else if (gcd(_gcd, num[j].fi) > maxGCD && !num[j].se) {
                put = j;
                maxGCD = gcd(_gcd, num[j].fi);
            }
        }
        b[i] = num[put].fi;
        num[put].se = true;
        _gcd = gcd(_gcd, b[i]);
    }


    for (int i = 0; i < n; ++i) cout << b[i] << " ";
    cout << el;
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
