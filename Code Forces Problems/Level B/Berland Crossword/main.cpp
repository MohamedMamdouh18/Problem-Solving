#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        int valid = 0;

        //U-R , U-L , D-R , D-L

        for (int mask = 0; mask < (1 << 4); ++mask) {
            int paintUp = u, paintDown = d, paintLeft = l, paintRight = r;
            if (mask & (1 << 0)) {
                paintDown--, paintLeft--;
            }
            if (mask & (1 << 1)) {
                paintDown--, paintRight--;
            }
            if (mask & (1 << 2)) {
                paintUp--, paintLeft--;
            }
            if (mask & (1 << 3)) {
                paintUp--, paintRight--;
            }

            if (paintRight < 0 || paintLeft < 0 || paintDown < 0 || paintUp < 0) continue;

            if ((n - 2) >= paintUp && (n - 2) >= paintDown && (n - 2) >= paintLeft && (n - 2) >= paintRight) {
                valid = 1;
                break;
            }
        }

        if (valid) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
