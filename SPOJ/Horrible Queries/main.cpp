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
    arr[2 * x + 1].se += arr[x].se;
    arr[2 * x + 1].fi += arr[x].se * (rx - lx) / 2;
    arr[2 * x + 2].se += arr[x].se;
    arr[2 * x + 2].fi += arr[x].se * (rx - lx) / 2;
    arr[x].se = 0;
}

void update(int l, int r, ll v, int x, int lx, int rx) {
    go_down(x, lx, rx);
    if (lx >= r || rx <= l)
        return;
    if (lx >= l && rx <= r) {
        arr[x].se += v;
        arr[x].fi += v * (rx - lx);
        return;
    }
    int m = (lx + rx) >> 1;
    update(l, r, v, 2 * x + 1, lx, m);
    update(l, r, v, 2 * x + 2, m, rx);
    arr[x].fi = arr[x * 2 + 1].fi + arr[x * 2 + 2].fi;
}

void update(int l, int r, ll v) {
    update(l, r, v, 0, 0, siz);
}

ll query(int l, int r, int x, int lx, int rx) {
    go_down(x, lx, rx);
    if (lx >= r || rx <= l)
        return 0ll;
    if (lx >= l && rx <= r)
        return arr[x].fi;
    int m = (lx + rx) >> 1;
    ll s1 = query(l, r, 2 * x + 1, lx, m);
    ll s2 = query(l, r, 2 * x + 2, m, rx);
    return s1 + s2;
}

ll query(int l, int r) {
    return query(l, r, 0, 0, siz);
}

void GREEN() {
    int n, c;
    cin >> n >> c;
    init(n);
    for (int i = 0; i < c; ++i) {
        ll op, l, r, v;
        cin >> op >> l >> r;
        if (op)
            cout << query(l - 1, r) << el;
        else {
            cin >> v;
            update(l - 1, r, v);
        }
    }
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
