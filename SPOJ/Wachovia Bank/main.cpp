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
const ll mod = 1e9 + 7, N = 55, M = 1050, INF = LONG_LONG_MAX;
const double eps = 1e-6;
int k, n;
bool visited[N][M];
int dp[N][M];
pair<int, int> item[M];

int recursive(int idx, int weight) {
    if (idx == n) return 0;
    if (visited[idx][weight]) return dp[idx][weight];
    visited[idx][weight] = true;
    int op1 = recursive(idx + 1, weight), op2 = 0;
    if (weight >= item[idx].fi) op2 = item[idx].se + recursive(idx + 1, weight - item[idx].fi);
    return dp[idx][weight] = max(op1, op2);
}

void GREEN() {
    cin >> k >> n;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i) {
        cin >> item[i].fi >> item[i].se;
    }
    cout << "Hey stupid robber, you can get ";
    cout << recursive(0, k) << "." << el;
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
