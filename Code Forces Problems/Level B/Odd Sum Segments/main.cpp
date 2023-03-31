#include <bits/stdc++.h>
 
using namespace std;
 
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        ll n, k, cuts = 0;
        cin >> n >> k;
        vector<ll> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            if (nums[i] & 1) cuts++;
        }
 
        if (cuts < k || (cuts - k & 1)) {
            cout << "NO" << el;
            continue;
        }
        cout << "YES" << el;
        k--;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] % 2 && k > 0) {
                cout << i + 1 << " ";
                k--;
            }
        }
        cout << n << " ";
        cout << el;
 
    }
}
