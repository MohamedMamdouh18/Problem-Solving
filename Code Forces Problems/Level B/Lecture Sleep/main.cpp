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

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x) {
            ans += num[i];
            num[i] = 0;
        }
    }
    int sum = 0 ,maxi;
    for (int i = 0; i < k; ++i) sum += num[i] ;
    maxi = sum ;
    for (int l = k; l < n; l++) {
        sum -= num[l-k] ;
        sum += num[l] ;
        maxi = max(maxi , sum) ;
    }
    cout << ans + maxi ;
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
