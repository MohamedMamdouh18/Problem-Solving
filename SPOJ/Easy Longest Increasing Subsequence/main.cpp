#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 15, M = 30, INF = LONG_LONG_MAX;
const double eps = 1e-6;
int n ;
bool visited[N][M];
int dp[N][M] , item[N] ;

int recursive(int idx, int last) {
    if (idx == n) return 0;
    if (visited[idx][last]) return dp[idx][last];
    visited[idx][last] = true;
    int op1 = recursive(idx + 1, last), op2 = 0;
    if (item[idx] > last) op2 = 1 + recursive(idx + 1, item[idx]);
    return dp[idx][last] = max(op1, op2);
}

void GREEN() {
    cin >> n ;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i) {
        cin >> item[i] ;
    }
    cout << recursive(0, 0)  << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
