#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 101, M = 20, INF = 1e-18;
vector<vector<int>> adj_list;
vector<bool> visited;
int n, m;

bool bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next: adj_list[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                if (next == m)
                    return true;
                q.push(next);
            }
        }
    }
    return false;
}

void LIGHT_BLUE() {
    cin >> n >> m;
    adj_list.resize(m + 1);
    visited.resize(m + 1);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = x + 1; j <= y; ++j)
            adj_list[x].pb(j);
    }
    if (bfs(0))
        cout << "YES";
    else
        cout << "NO";
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
