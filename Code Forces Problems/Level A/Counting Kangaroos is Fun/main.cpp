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
    int n, ans;
    cin >> n;
    ans = n;
    vector<int> kang(n);
    for (int i = 0; i < n; ++i) cin >> kang[i];

    sort(all(kang));
    int l = 0, r = n / 2;
    while (l < n / 2 && r < n) {
        if (2 * kang[l] <= kang[r]) l++, ans--;
        r++;
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
