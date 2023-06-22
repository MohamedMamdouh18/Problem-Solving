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


void LIGHT_BLUE() {
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
            a[i][j] = 1 ;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!b[i][j]) {
                for (int k = 0; k < n; ++k)
                    a[k][j] = 0;
                for (int k = 0; k < m; ++k)
                    a[i][k] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j]) {
                int num = 0;
                for (int k = 0; k < n; ++k) {
                    num |= a[i][k];
                    num |= a[k][j];
                }
                if (!num) {
                    cout << "NO" << el;
                    return;
                }
            } else {
                int num = 0;
                for (int k = 0; k < n; ++k) {
                    num |= a[i][k];
                    num |= a[k][j];
                }
                if (num) {
                    cout << "NO" << el;
                    return;
                }
            }
        }
    }
    cout << "YES" << el;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << el;
    }
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
