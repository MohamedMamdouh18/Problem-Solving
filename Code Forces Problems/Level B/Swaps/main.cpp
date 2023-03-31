#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        ll n, ans = INT_MAX, x;
        cin >> n;
        set<pair<ll, ll>> odd, even;
        vector<ll> movingOdd(n, LONG_LONG_MAX);
        for (int i = 0; i < n; ++i) {
            cin >> x;
            odd.insert({x, i});
        }
        for (int i = 0; i < n; ++i) {
            cin >> x;
            even.insert({x, i});
        }
 
        auto oddIt = odd.begin();
        auto evenIt = even.begin();
 
        for (int i = 0; i < n; ++i) {
            ll moveOdd = (*(oddIt++)).se;
            ll moveEven = (*(evenIt++)).se;
            if (i == 0) movingOdd[i] = moveOdd;
            else movingOdd[i] = min(moveOdd, movingOdd[i - 1]);
 
            ll ind = movingOdd[i] + moveEven;
            ans = min(ans, ind);
        }
        cout << ans << el;
    }
}
