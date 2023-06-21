#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1000406, M = 20, INF = LONG_LONG_MAX;

vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> color;
int pos = 0, neg = 0;

void dfs(int cur) {
    visited[cur] = true;
    if (color[cur])
        pos ++;
    else
        neg ++;

    for (int i = 0; i < adj_list[cur].size(); ++i) {
        int next = adj_list[cur][i];
        if (!visited[next]) {
            color[next] = !color[cur];
            dfs(next);
        }
    }
}

void LIGHT_BLUE() {
    ll n, ans = 0;
    cin >> n;
    adj_list.resize(n + 1);
    visited.resize(n + 1);
    color.assign(n + 1, -1);

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj_list[x].pb(y);
        adj_list[y].pb(x);
    }
    color[1] = 0;
    dfs(1);
    for (int i = 1; i <= n ; ++i) {
        if(color[i])
            ans += (neg - adj_list[i].size()) ;
    }
    cout << ans << el ;
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        LIGHT_BLUE();
    }
}
