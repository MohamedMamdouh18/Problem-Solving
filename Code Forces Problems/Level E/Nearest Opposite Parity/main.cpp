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
const ll mod = 1e9 + 7, N = 1e6 + 1;
int n;
bool visited[N];
vector<vector<int>> adj;
vector<int> dist, num, ans;
 
void bfs(int pos) {
    queue<int> q;
    for (int i = 0; i < num.size(); ++i) {
        if ((num[i] & 1) ^ pos) {
            q.push(i);
            dist[i] = 0;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int child: adj[cur]) {
            if (dist[child] > dist[cur] + 1) {
                dist[child] = dist[cur] + 1;
                q.push(child);
            }
        }
    }
    for (int i = 0; i < dist.size(); ++i) {
        if (!((num[i] & 1) ^ pos)) ans[i] = dist[i];
    }
}
 
void GREEN() {
    cin >> n;
    dist.resize(n), num.resize(n), ans.resize(n), adj.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        dist[i] = 1e9;
        int l = i - num[i];
        int r = i + num[i];
        if (l >= 0) adj[l].pb(i);
        if (r < n) adj[r].pb(i);
    }
    bfs(0);
    dist.assign(n, 1e9);
    bfs(1);
    for (int i = 0; i < dist.size(); ++i) {
        cout << ((ans[i] == 1e9) ? -1 : ans[i]) << " ";
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
