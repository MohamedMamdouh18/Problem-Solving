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
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = INT_MIN;
int n, s = 0;
double dist[31][31];

bool FloyedWarshell() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] > 0.0 && dist[k][j] > 0.0)
                    dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] > 1.0) return true;
    }
    return false;
}

void GREEN() {
    while (cin >> n && n) {
        s++;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) dist[i][j] = 0.0;
                else dist[i][j] = 1.0;
            }
        }
        map<string, int> currency;
        int q;
        double w;
        string x, y;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            currency[x] = i;
        }
        cin >> q;
        for (int i = 0; i < q; ++i) {
            cin >> x >> w >> y;
            dist[currency[x]][currency[y]] = max(w, dist[currency[x]][currency[y]]);
        }
        cout << "Case " << s << ": " << ((FloyedWarshell()) ? "Yes" : "No") << el;
    }
}

int main() {
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
