#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int moves = -1;

void solve(int n, int m, int move) {
    if (n > m) return;
    if (m == n) moves = move;
    solve(n * 2, m, move + 1);
    solve(n * 3, m, move + 1);
}

int main() {
    IOS
    int n, m;
    cin >> n >> m;
    solve(n, m, 0);
    cout << moves;
}
