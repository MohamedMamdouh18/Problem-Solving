#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    int n, maxi = INT_MIN, ans = -1;
    cin >> n;
    vector<int> pir(n);
    for (int i = 0; i < n; ++i) cin >> pir[i];
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            if (pir[i] > maxi && pir[i] > pir[i + 1]) {
                maxi = pir[i];
                ans = i + 1;
            }
        } else if (i == n - 1) {
            if (pir[i] > maxi && pir[i] > pir[i - 1]) {
                maxi = pir[i];
                ans = i + 1;
            }
        } else {
            if (pir[i] > maxi &&
                ((pir[i] >= pir[i + 1] && pir[i] > pir[i - 1]) || (pir[i] > pir[i + 1] && pir[i] >= pir[i - 1]))) {
                maxi = pir[i];
                ans = i + 1;
            }
        }
    }
    cout << ans << el;
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
