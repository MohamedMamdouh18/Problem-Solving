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
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << 1 << el;
            continue;
        }
        k--;
        if (n & 1) {
            int step = n / 2;
            int b = (k + k / step) % n;
            cout << b + 1 << el;

        } else cout << (k % n) + 1 << el;
    }
}
