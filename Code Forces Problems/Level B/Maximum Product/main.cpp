#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define ll long long
#define all(a) a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        ll n, sum = LONG_LONG_MIN;
        cin >> n;
        vector<ll> num(n);
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        sort(num.begin(), num.end());
        sum = max(sum, num[0] * num[1] * num[2] * num[3] * num[n - 1]);
        sum = max(sum, num[0] * num[1] * num[n - 3] * num[n - 2] * num[n - 1]);
        sum = max(sum, num[n - 5] * num[n - 4] * num[n - 3] * num[n - 2] * num[n - 1]);

        cout << sum << el;

    }
}
