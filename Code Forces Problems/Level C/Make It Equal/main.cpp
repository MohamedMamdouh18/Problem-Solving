#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, k, ans = 0, slice = 0, mini = INT_MAX, maxi = INT_MIN;
    cin >> n >> k;
    vector<int> height(n);
    vector<int> slices(2e5 + 2);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
        mini = min(mini, height[i]);
        maxi = max(maxi, height[i]);
    }
    for (int i = 0; i < n; ++i) if (height[i] > mini) slices[height[i]]++;
    for (int i = maxi; i > mini; --i) {
        slices[i] += slices[i + 1];
        slice += slices[i];
        if (slice > k) {
            slice = slices[i];
            ans++;
        }
    }
    if(slice > 0) ans ++ ;

    cout << ans;
}
