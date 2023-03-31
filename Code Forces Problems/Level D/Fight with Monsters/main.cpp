#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    int n, a, b, k, ans = 0, x;
    cin >> n >> a >> b >> k;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        int temp = x % (a + b);
        if (temp <= a && temp > 0) ans++;
        else nums.pb((temp == 0) ? b : temp - a);
    }
    for (int i = 0; i < nums.size(); ++i) nums[i] = ceil((double) nums[i] / a);
    sort(all(nums));
    for (int i = 0; i < nums.size(); ++i) {
        if (k >= nums[i]) {
            ans++;
            k -= nums[i];
        } else break;
    }
    cout << ans;

}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
