#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, ans = INT_MAX;
        cin >> n;
        vector<int> athlete(n);
        for (int i = 0; i < n; ++i) cin >> athlete[i];

        sort(all(athlete));
        for (int i = 0; i < n - 1; ++i) ans = min(ans, athlete[i + 1] - athlete[i]);
        cout << ans << el;
    }
}
