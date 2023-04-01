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
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

struct node {
    int row;
    int col;
    int cost;
};

int bfs(pair<int, int> start, pair<int, int> end) {
    queue<node> q;
    q.push({start.fi, start.se, 0});
    while (!q.empty()) {
        node current = q.front();
        if (current.row == end.first && current.col == end.second) return current.cost;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            node x{};
            x.row = current.row + dx[i];
            x.col = current.col + dy[i];
            x.cost = current.cost + 1;
            if (x.row == end.first && x.col == end.second) return x.cost;
            if (x.row > 0 && x.row < 9 && x.col > 0 && x.col < 9)q.push(x);
        }
    }

}

void GREEN() {
    string pos1, pos2;
    while (cin >> pos1 >> pos2) {
        int col1 = pos1[0] - 'a' + 1, col2 = pos2[0] - 'a' + 1;
        int row1 = pos1[1] - '0', row2 = pos2[1] - '0';
        int mini = bfs({row1, col1}, {row2, col2});
        cout << "To get from " << pos1 << " to " << pos2 << " takes " << mini << " knight moves." << endl;
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
