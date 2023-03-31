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
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    for (int i = 0; i < n - 1; ++i) {
        if (k == 0) break;
        int move = min(k, num[i]);
        num[i] -= move;
        k -= move;
        num[num.size() - 1] += move ;
    }
    for (int i = 0; i < n; ++i) cout << num[i] << " " ;
    cout << el ;
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
