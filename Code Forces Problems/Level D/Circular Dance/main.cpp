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
const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;
vector<vector<int>> adj;
 
 
void GREEN() {
    int n, x, y;
    cin >> n;
    adj.resize(n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        adj[i].pb(x);
        adj[i].pb(y);
    }
    int put = 1, cur = 1;
    ans.pb(1);
    while (put < n) {
        int first = adj[cur][0];
        int second = adj[cur][1];
 
        if (adj[first][0] == second || adj[first][1] == second) {
            ans.pb(first);
            ans.pb(second);
            cur = second;
        } else {
            ans.pb(second);
            ans.pb(first);
            cur = first;
        }
        put += 2;
    }
    if (!(n & 1)) ans.pop_back();
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
 
}
 
int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
