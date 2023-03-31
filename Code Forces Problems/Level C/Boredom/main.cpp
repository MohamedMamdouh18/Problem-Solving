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
const ll mod = 1e9 + 7, N = 1e5 + 50, M = 1050, INF = LONG_LONG_MAX;
const double eps = 1e-6;
bool visited[N];
ll dp[N];
vector<pair<ll, ll>> num;

ll recursive(int idx) {
    if (idx >= num.size()) return 0;
    if (visited[idx]) return dp[idx];
    visited[idx] = true;
    ll op1 = 0, op2 = 0;
    if (idx < num.size() - 1) {
        if (num[idx].fi == num[idx + 1].fi - 1) {
            op1 = num[idx].fi * num[idx].se + recursive(idx + 2);
            op2 = recursive(idx + 1);
        } else op1 = num[idx].fi * num[idx].se + recursive(idx + 1);
    } else op1 = num[idx].fi * num[idx].se + recursive(idx + 2);
    return dp[idx] = max(op1, op2);
}

void GREEN() {
    ll n, x;
    map<ll, ll> occur;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        occur[x]++;
    }
    for (auto item: occur) num.pb(item);
    cout << recursive(0);
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
