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
    int n, maxi = 0, last = -1, ans = INT_MAX;
    cin >> n;
    vector<int> num(n);
    map<int, int> freq;
    for (int i = 0; i < n; ++i) cin >> num[i];
    if (n == 1) {
        cout << -1 << el;
        return;
    }
    freq[num[0]]++;
    maxi = num[0];
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && freq[num[r]] < 2) {
            r++;
            freq[num[r]]++;
            if (freq[num[r]] > freq[maxi]) maxi = num[r];
        }
        if (freq[maxi] > 1)ans = min(r - l + 1, ans);
        freq[num[l]]--;
        if (ans == 2) break;
    }
    cout << ((ans == INT_MAX) ? -1 : ans) << el;
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
