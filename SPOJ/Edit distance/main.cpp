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
const ll mod = 1e9 + 7, N = 2100, M = 2100, INF = LONG_LONG_MAX;
const double eps = 1e-6;
int dp[N][M];
string s1, s2;

int solve(int ptr1, int ptr2) {
    if (ptr1 == s1.size() || ptr2 == s2.size()) {
        return max(s1.size() - ptr1, s2.size() - ptr2);
    }
    if (~dp[ptr1][ptr2]) return dp[ptr1][ptr2];
    int op1 = 0, op2 = 0, op3 = 0;
    if (s1[ptr1] != s2[ptr2]) {
        op1 = 1 + solve(ptr1 + 1, ptr2 + 1);
        op2 = 1 + solve(ptr1 + 1, ptr2);
        op3 = 1 + solve(ptr1, ptr2 + 1);
        return dp[ptr1][ptr2] = min({op1, op2, op3});
    } else
        return dp[ptr1][ptr2] = solve(ptr1 + 1, ptr2 + 1);
}

void GREEN() {
    cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
