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

int divisor[1000001], ans[11][1000001];

void sieve() {
    for (int i = 2; i <= 1000000; i++) {
        if (divisor[i] == 0) for (int j = i; j <= 1000000; j += i) divisor[j]++;
    }

    for (int n = 0; n <= 10; n++) {
        for (int i = 1; i <= 1000000; ++i) ans[n][i] += ans[n][i - 1] + (divisor[i] == n);
    }
}

void GO() {
    int a, b, n;
    cin >> a >> b >> n;
    cout << ans[n][b] - ans[n][a-1]<< el;

}

int main() {
    IOS
    PREC
    sieve();

    int tc = 1;
    cin >> tc;
    while (tc--) {
        GO();
    }
}
