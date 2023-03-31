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
        int n, x, maxi = -1, mode = 0, ans = 0;
        cin >> n;
        map<int, int> freq1;
        map<int, int> freq2;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            freq1[x]++;
            freq2[freq1[x]]++;
        }

        for (auto item: freq2) {
            if (item.fi * item.se > maxi * mode) {
                maxi = item.se;
                mode = item.fi;
            }
        }
        for (auto item: freq1) {
            if (item.se != 0) {
                if (item.se < mode) ans += item.se;
                else ans += abs(item.se - mode);
            }
        }

        cout << ans << el;
    }
}
