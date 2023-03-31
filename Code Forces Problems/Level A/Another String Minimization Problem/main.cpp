#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e6;

void GREEN() {
    int n, m, x;
    cin >> n >> m;
    vector<char> word(m, 'B');
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (word[x - 1] == 'A') word[m - x] = 'A';
        else if (word[m - x] == 'A') word[x - 1] = 'A';
        else word[min(x - 1, m - x)] = 'A';
    }
    for (int i = 0; i < m; ++i) cout << word[i];
    cout << el;
}

int main() {
    IOS
    PREC

    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
