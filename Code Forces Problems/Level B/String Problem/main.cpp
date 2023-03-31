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
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = INT_MAX;
int dist[26][26];

void FloyedWarshell() {
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void GREEN() {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) if (i != j)dist[i][j] = INF;
    }
    int m, w, ans = 0;
    string s1, s2;
    char x, y;
    cin >> s1 >> s2;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> w;
        dist[x - 'a'][y - 'a'] = min(w, dist[x - 'a'][y - 'a']);
    }
    if (s1.size() != s2.size()) {
        cout << -1;
        return;
    }
    FloyedWarshell();
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) continue;
        int cur = INF, ind;
        for (int j = 0; j < 26; ++j) {
            if (dist[s1[i] - 'a'][j] < INF && dist[s2[i] - 'a'][j] < INF)
                if (dist[s1[i] - 'a'][j] + dist[s2[i] - 'a'][j] < cur) {
                    cur = dist[s1[i] - 'a'][j] + dist[s2[i] - 'a'][j];
                    ind = j;
                }
        }
        if (cur == INF) {
            cout << -1;
            return;
        }
        s1[i] = (char) (ind + 'a');
        s2[i] = (char) (ind + 'a');
        ans += cur;
    }
    cout << ans << el;
    cout << s1;
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
