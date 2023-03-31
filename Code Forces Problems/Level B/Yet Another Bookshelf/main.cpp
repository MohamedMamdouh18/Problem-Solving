#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, x, zeros = 0, ans = 0, first = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x == 0) {
                zeros++;
            } else {
                if (first)ans += zeros;
                zeros = 0;
                first = 1;
            }
        }
        cout << ans << el;
    }
}
