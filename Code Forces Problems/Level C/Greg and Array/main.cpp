#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct op {
    ll l;
    ll r;
    ll d;
};

int main() {
    IOS
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> num(n + 1);
    vector<ll> pref(n + 2, 0);
    vector<op> operation(m + 2);
    vector<int> queries(m + 2);

    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 1; i <= m; ++i) cin >> operation[i].l >> operation[i].r >> operation[i].d;

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        queries[x]++;
        queries[y + 1]--;
    }

    for (int i = 1; i < m + 1; ++i) {
        queries[i] += queries[i - 1];
        pref[operation[i].l] += operation[i].d * queries[i];
        pref[operation[i].r + 1] -= operation[i].d * queries[i];
    }

    for (int i = 1; i <= n; ++i) pref[i] += pref[i - 1];

    for (int i = 1; i <= n; ++i) cout << num[i] + pref[i] << " ";
}
