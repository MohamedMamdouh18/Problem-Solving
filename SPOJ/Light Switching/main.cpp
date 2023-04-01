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
const ll mod = 1e9, N = 1e6 + 50, INF = LONG_LONG_MAX;

int siz;
vector<pair<ll, ll>> arr;

void init(int n) {
    siz = 1;
    arr.clear();
    while (siz < n) siz *= 2;
    arr.assign(2 * siz, {0, 0});
}

void go_down(int x, int lx, int rx) {
    if (rx - lx == 1 || arr[x].se == 0)
        return;
    arr[2 * x + 1].se = 1 - arr[2 * x + 1].se;
    arr[2 * x + 1].fi = abs((rx - lx) / 2 - arr[2 * x + 1].fi);
    arr[2 * x + 2].se = 1 - arr[2 * x + 2].se;
    arr[2 * x + 2].fi = abs((rx - lx) / 2 - arr[2 * x + 2].fi);
    arr[x].se = 0;
}

void update(int l, int r, int x, int lx, int rx) {
    go_down(x, lx, rx);
    if (lx >= r || rx <= l)
        return;
    if (lx >= l && rx <= r) {
        arr[x].se = 1 - arr[x].se;
        arr[x].fi = abs((rx - lx) - arr[x].fi);
        return;
    }
    int m = (lx + rx) >> 1;
    update(l, r, 2 * x + 1, lx, m);
    update(l, r, 2 * x + 2, m, rx);
    arr[x].fi = arr[x * 2 + 1].fi + arr[x * 2 + 2].fi;
}

void update(int l, int r) {
    update(l, r, 0, 0, siz);
}

ll query(int l, int r, int x, int lx, int rx) {
    go_down(x, lx, rx);
    if (lx >= r || rx <= l)
        return 0;
    if (lx >= l && rx <= r)
        return arr[x].fi;
    int m = (lx + rx) >> 1;
    ll s1 = query(l, r, 2 * x + 1, lx, m);
    ll s2 = query(l, r, 2 * x + 2, m, rx);
    return s1+ s2;
}

ll query(int l, int r) {
    return query(l, r, 0, 0, siz);
}

void GREEN() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; ++i) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op)
            cout << query(l - 1, r) << el;
        else
            update(l - 1, r);
    }
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
