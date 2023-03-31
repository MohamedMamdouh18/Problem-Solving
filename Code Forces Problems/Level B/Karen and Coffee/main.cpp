
#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, k, q, mn = 200002, mx = 0;
    cin >> n >> k >> q;
    vector<int> agree(200002, 0), prefix(200002, 0);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        mn = min(mn, min(l, r));
        mx = max(mx, max(l, r));
        agree[l]++;
        agree[r + 1]--;
    }
    for (int i = mn; i <= mx; ++i) agree[i] += agree[i - 1];
    for (int i = 1; i < prefix.size(); ++i) {
        if (agree[i] >= k) prefix[i] = 1;
        prefix[i] += prefix[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << el;
    }
}
