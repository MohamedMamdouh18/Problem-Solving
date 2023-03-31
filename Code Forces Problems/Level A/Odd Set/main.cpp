#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    int n, x, odd = 0, even = 0;
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> x;
        if (x & 1) odd++;
        else even++;
    }
    cout << ((even == odd) ? "YES" : "NO") << el;
}

int main() {
    IOS
    PREC

    int tc = 1;
    cin >> tc;
    while (tc--) {
        GO();
    }
}
