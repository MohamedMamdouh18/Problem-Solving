#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    while (l < r - 1) {
        if (a[l] > a[r]) {
            a[l] -= a[r];
            r--;
        } else if (a[l] < a[r]) {
            a[r] -= a[l];
            l++;
        } else {
            l++;
            r--;
        }
    }
   if(l != r) cout << l + 1 << " " << n - r;
   else cout << l + 1 << " " << n - r - 1;
}
