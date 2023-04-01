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
const int mod = 1e9 + 7, N = 1e6 + 50, M = 30, INF = INT_MAX;
const double eps = 1e-6;

int table[N][M], lg[N], n, a[N];

void build() {
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < n; ++i)
        table[i][0] = a[i];
    for (int bit = 1; bit < M; bit++) {
        for (int i = 0; i + (1 << bit) <= n; ++i) {
            table[i][bit] = max(table[i][bit - 1], table[i + (1 << (bit - 1))][bit - 1]);
        }
    }
}

//l & r are 0 based
int QeurySum(int l, int r) {
    int dist = r - l + 1, idx = l, sum = 0;
    for (int bit = M; bit >= 0; --bit) {
        if ((1 << bit) <= dist) {
            dist -= (1 << bit);
            sum += table[l][bit];
            l = (1 << bit);
        }
    }
    return sum;
}

int QueryMax(int l, int r) {
    int dist = lg[r - l + 1];
    return max(table[l][dist], table[r - (1 << dist) + 1][dist]);
}

void GREEN() {
    int q, l, r, ans = 0;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build();
    while (q--) {
        cin >> l >> r;
        l--, r--;
        if (QueryMax(l, r - 1) == a[l]) ans++;
    }
    cout << ans;
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
