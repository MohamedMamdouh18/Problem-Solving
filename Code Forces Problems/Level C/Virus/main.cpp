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
const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;

void GREEN() {
    int n, m;
    cin >> n >> m;
    vector<int> special(m);
    for (int i = 0; i < m; ++i) cin >> special[i];
    sort(all(special));
    vector<int> infected;
    for (int i = 0; i < m - 1; ++i) infected.pb(special[i + 1] - special[i] - 1);
    infected.pb(n - special[m - 1] + special[0] - 1 );
    sort(infected.rbegin(), infected.rend());
    int days = 0;
    for (int i = 0; i < infected.size(); ++i) {
        if (infected[i] >= 2 * days) m += 2 * days;
        else m += infected[i] ;
        days++;
        if (infected[i] >= 2 * days) m++;
        days++;
    }
    cout << m << el;

}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
