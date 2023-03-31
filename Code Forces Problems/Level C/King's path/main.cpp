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
map<int, set<pair<int, int>>> allow;
map<pair<int, int>, bool> visited;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

struct node {
    int x;
    int y;
    int cost;
};

int bfs(int x1, int y1, int x2, int y2) {
    queue<node> q;
    q.push({x1, y1, 0});
    visited[{x1, y1}] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.x == x2 && cur.y == y2) return cur.cost;
        for (int i = 0; i < 8; ++i) {
            int newX = cur.x + dx[i];
            int newY = cur.y + dy[i];
            int newCost = cur.cost + 1;

            if (allow.count(newX) && !visited[{newX, newY}]) {
                auto allowed = allow[newX].upper_bound({newY, 1e9 + 2});
                allowed--;
                if ((*allowed).fi <= newY && (*allowed).se >= newY) {
                    q.push({newX, newY, newCost});
                    visited[{newX, newY}] = true;
                }
            }
        }
    }
    return -1;
}

void GREEN() {
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        allow[a].insert({b, c});
    }
    cout << bfs(x1, y1, x2, y2);

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
