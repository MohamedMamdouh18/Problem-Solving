#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;

void GREEN() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> block(n);
    for (int i = 0; i < n; ++i) cin >> block[i];
    for (int i = 0; i < n - 1; ++i) {
        if (abs(block[i] - block[i + 1]) > k) {
            if (block[i] > block[i + 1]) m += (block[i] - block[i + 1]) + ((block[i + 1] < k) ? block[i + 1] : k);
            else {
                int need = block[i + 1] - k - block[i];
                if (need > m) {
                    cout << "NO" << el;
                    return;
                } else m -= need;
            }
        } else if (block[i] > block[i + 1])
            m += (block[i] - block[i + 1]) + ((block[i + 1] < k) ? block[i + 1] : k);
        else m += ((k > block[i + 1]) ? block[i] : block[i] - (block[i + 1] - k));
    }
    cout << "YES" << el;
}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
