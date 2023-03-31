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
    vector<int> num(n), ans(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    sort(all(num));
    int j = 0;
    for (int i = 0; i < n; i += 2) ans[i] = num[j++];
    for (int i = (n % 2 == 0 ? n - 1 : n - 2); i > 0; i -= 2) ans[i] = num[j++];
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
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
