#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
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
    int n, sum, ans = INT_MIN, one = 0;
    cin >> n >> sum;
    vector<int> bits(n);
    for (int i = 0; i < n; ++i) {
        cin >> bits[i];
        if (bits[i]) one++;
    }
    if (one < sum) {
        cout << -1 << el;
        return;
    } else if (one == sum) {
        cout << 0 << el;
        return;
    }
 
    int r = 0, current = 0;
    while (current < sum) current += bits[r++];
    for (int l = 0; l < bits.size(); ++l) {
        while (r < bits.size() && bits[r] != 1) r++;
        if (current == sum) ans = max(ans, r - l);
        while (l < bits.size() && bits[l] != 1) l++;
        r++;
    }
    cout << n - ans << el;
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
