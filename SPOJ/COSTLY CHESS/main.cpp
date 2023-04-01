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
int dist[8][8];
vector<vector<pair<int, ll>>> adj;
int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};

void dijkstra(int s1, int s2) {
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, {s1, s2}});
    dist[s1][s2] = 0;
    while (!q.empty()) {
        int cost = -q.top().fi;
        int a = q.top().se.fi;
        int b = q.top().se.se;
        q.pop();
        if (cost > dist[a][b]) continue;
        for (int i = 0; i < 8; ++i) {
            int c = a + dx[i];
            int d = b + dy[i];
            int new_cost = a * c + b * d + cost;
            if (c >= 0 && d >= 0 && c < 8 && d < 8 && dist[c][d] > new_cost) {
                dist[c][d] = new_cost;
                q.push({-new_cost, {c, d}});
            }
        }
    }
}

void GREEN() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        for (auto &i: dist) {
            for (int &j: i) j = INT_MAX;
        }
        dijkstra(a, b);
        cout << ((dist[c][d] == INT_MAX) ? -1 : dist[c][d]) << el;
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
