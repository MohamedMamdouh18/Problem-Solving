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
    int n, x, first;
    cin >> n;
    vector<pair<int, int>> block(n + 1), last(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (i == 0) first = x, block[x].first = block[x].second = 1;

        if (last[x].first == 0 && x != first) {
            block[x].first = block[x].second = 1, last[x].first = i;
        } else {
            if ((i - last[x].first) & 1) {
                block[x].first++;
                last[x].first = i;
            } else if (last[x].second == 0) last[x].second = i;
            if ((i - last[x].second) & 1 && last[x].second != 0) {
                block[x].second++;
                last[x].second = i;
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) cout << max(block[i].first, block[i].second) << " ";
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
