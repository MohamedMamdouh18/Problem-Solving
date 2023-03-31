#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, x, ans = INT_MIN;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if ( (x - (i + 1)) > ans) ans = x - (i + 1);
        }
        cout << ans << el;
    }
}
