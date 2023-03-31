#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, valid = 0;
    cin >> n;
    vector<int> rot(n);
    for (int i = 0; i < n; ++i) {
        cin >> rot[i];
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) sum += rot[i];
            else sum -= rot[i];
        }
        if (sum == 0 || sum % 360 == 0) {
            valid = 1;
            break;
        }
    }

    if (valid) cout << "yes";
    else cout << "no";
}
