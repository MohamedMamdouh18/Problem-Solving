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
    int n;
    cin >> n;
    vector<int> student(n);
    for (int i = 0; i < n; ++i) cin >> student[i];
    sort(all(student));
    int r = 1, ans = INT_MIN;
    for (int l = 0; l < n; ++l) {
        while (r < n && student[r] - student[l] <= 5) r++;
        ans = max(ans, r - l);
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
