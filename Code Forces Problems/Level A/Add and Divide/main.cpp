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
vector<int> edge;

struct node {
    ll a, b, cost;
};

ll bfs(ll a, ll b) {
    queue<node> q;
    q.push({a, b, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        ll child = cur.a / cur.b;
        if (child == 0) return cur.cost + 1;
        q.push({cur.a, cur.b + 1, cur.cost + 1});
        if(cur.b != 1) q.push({child, cur.b, cur.cost + 1});
    }

}

void GREEN() {
    ll a, b;
    cin >> a >> b;
    cout << bfs(a, b) << el;
}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
