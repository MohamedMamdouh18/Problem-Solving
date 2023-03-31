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
        int n, k, cat = 0, ans = 0;
        cin >> n >> k;
        vector<int> mice(k);
        for (int i = 0; i < k; ++i) cin >> mice[i];
        sort(mice.rbegin(), mice.rend());
        for (int i = 0; i < mice.size(); ++i) {
            if (cat >= mice[i]) break;
            cat += n - mice[i];
            ans++;
        }
        cout << ans << el;

    }
}
