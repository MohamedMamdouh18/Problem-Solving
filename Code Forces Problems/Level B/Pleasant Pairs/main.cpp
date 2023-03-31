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
 
void GREEN() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> num(n+1);
    for (int i = 1; i <= n; ++i) cin >> num[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = num[i] - i; j <= n; j += num[i]) {
            if (j > i) {
                if (num[i] * num[j] == i + j) ans++;
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
        GREEN();
    }
}
