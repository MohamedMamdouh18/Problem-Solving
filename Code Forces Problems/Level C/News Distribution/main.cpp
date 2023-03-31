#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
vector<int> parent;
vector<int> siz;
 
int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
 
void join(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b) return;
    if (siz[b] > siz[a]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
}
 
void GO() {
    int n, m, k, x, y;
    cin >> n >> m;
    siz.assign(n, 1);
    parent.resize(n);
    for (int i = 0; i < n; ++i) parent[i] = i;
 
    for (int i = 0; i < m; ++i) {
        cin >> k;
        if (k > 0)cin >> x;
        x--;
        for (int j = 1; j < k; ++j) {
            cin >> y;
            y--;
            join(x, y);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << siz[find(i)] << " ";
    }
 
}
 
int main() {
    IOS
    PREC
 
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
