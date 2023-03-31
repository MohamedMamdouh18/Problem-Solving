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

bool divisor[100021];
vector<ll> prime;

void sieve() {
    for (ll i = 2; i <= 100020; i++) {
        if (!divisor[i]) {
            prime.pb(i);
            for (ll j = i * i; j <= 100020; j += i)
                divisor[j] = true;
        }
    }
}

void GO() {
    int n, m, ans = INT_MAX;
    cin >> n >> m;
    int mat[n][m];
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
            mat[i][j] = (*lower_bound(all(prime), mat[i][j]) - mat[i][j]);
            sum += mat[i][j];
        }
        ans = min(ans, sum);
    }
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) sum += mat[j][i];
        ans = min(ans, sum);
    }
    cout << ans;
}

int main() {
    IOS
    PREC
    sieve();

    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
