#include <bits/stdc++.h>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int k, n, m, fedor, ans = 0;
    cin >> n >> m >> k;
 
    vector<int> players(m);
    for (int i = 0; i < m; ++i) {
        cin >> players[i];
    }
    cin >> fedor;
 
    bitset<20> fedorArmy = fedor;
    for (int i = 0; i < m; ++i) {
        bitset<20> player = players[i];
        if (player.operator^=(fedorArmy).count() <= k) ans++;
    }
 
    cout << ans;
}
