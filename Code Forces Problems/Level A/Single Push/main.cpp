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
        int n, x, same = INT_MIN,  pass = 0, flag = 1;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) {
            c[i] = b[i] - a[i];
            if (c[i] < 0) flag = 0;
        }
        if (!flag) {
            cout << "NO" << el;
            continue;
        }
        for (int i = 0; i < c.size(); ++i) {
            if ((pass && c[i]) || (c[i] && same != c[i] && same != INT_MIN) ) {
                flag = 0;
                break;
            }
            if (c[i] && same == INT_MIN) same = c[i];
            if (!c[i] && same != INT_MIN) pass = 1;
        }

        cout << ((flag) ? "YES" : "NO") << el;

    }
}
