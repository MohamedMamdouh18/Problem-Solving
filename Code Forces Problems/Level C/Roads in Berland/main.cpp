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
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = LONG_LONG_MAX;
int n, t;
ll dist[300][300];
 
void GREEN() {
    ll sum = 0, q ,x , y , w;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dist[j][i] = dist[i][j] ;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) sum += dist[i][j] ;
    }
    cin >> q ;
    while (q --){
        cin >> x >> y >> w;
        x-- , y --;
        if(dist[x][y] < w) {
            cout << sum << " ";
            continue;
        }
        sum -= dist[x][y] ,sum += w ;
        dist[x][y] = w ,dist[y][x] = w ;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(dist[i][j] > dist[i][x] + dist[x][y] + dist[y][j]){
                    sum -= dist[i][j] ;
                    dist[i][j] = dist[i][x] + dist[x][y] + dist[y][j] ;
                    dist[j][i] = dist[i][x] + dist[x][y] + dist[y][j] ;
                    sum += dist[i][j] ;
                }
            }
        }
        cout << sum << " " ;
    }
}
 
int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
