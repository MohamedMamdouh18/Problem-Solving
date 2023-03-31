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
const ll mod = 1e9 + 7, N = 1e5 + 1;
vector<vector<int>> adj;
vector<int> ans;
vector<bool> visited;
int maxi = INT_MIN;
struct node {
    int cur;
    int col;
    int parCol;
};

void bfs(int start) {
    queue<node> q;
    q.push({start, 1, -1});
    visited[start] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        maxi = max(cur.col, maxi);
        ans[cur.cur] = cur.col;
        int i = 1;
        for (auto child: adj[cur.cur]) {
            if (!visited[child]) {
                while (i == cur.col || i == cur.parCol) i++;
                visited[child] = true;
                q.push({child, i, cur.col});
                i++;
            }
        }
    }
}

void GREEN() {
    int n, x, y;
    cin >> n;
    adj.resize(n + 1), ans.resize(n + 1), visited.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) bfs(i);
    }
    cout << maxi << el;
    for (int i = 1; i < ans.size(); ++i) {
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
