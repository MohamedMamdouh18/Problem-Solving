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

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> fact;
    for (int i = 2; i * i < n; ++i) {
        if (n % i == 0) {
            fact.emplace_back(i, 0);
            while (n % i == 0) n /= i, fact.back().se++;
        }
    }
    if (n > 1) fact.emplace_back(n, 1);
    return fact;
}

void GO() {
    int n, ans = 0;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (factorize(i).size() == 2) ans++;
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
