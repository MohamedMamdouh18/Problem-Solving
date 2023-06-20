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

vector<vector<ll>> adj_list;
vector<bool> visited;
ll node = 0;
map<pair<ll, ll>, bool> edges;

void dfs(ll cur) {
    node++;
    for (int i = 0; i < adj_list[cur].size(); ++i) {
        ll next = adj_list[cur][i];
        edges[{min(cur, next), max(cur, next)}] = true;
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

void LIGHT_BLUE() {
    ll n, m;
    cin >> n >> m;
    adj_list.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj_list[x].pb(y);
        adj_list[y].pb(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i);

            ll edge_no = edges.size();
            if (edge_no < (node * (node - 1ll)) / 2ll) {
                cout << "NO";
                return;
            }

            edges.clear();
            node = 0;
        }
    }

    cout << "YES" << el;
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
