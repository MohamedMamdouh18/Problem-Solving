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

bool prime[N];

void seive() {
    prime[1] = true;
    for (ll i = 2; i < N; ++i) {
        if (!prime[i])
            for (ll j = i * i; j < N; j += i)
                prime[j] = true;
    }
}

struct node {
    ll ans, num;

    node() {
        ans = 0, num = 0;
    }
};

int siz, t = 0;
vector<node> arr;

void init(int n) {
    siz = 1;
    arr.clear();
    while (siz < n) siz *= 2;
    arr.resize(2 * siz);
}

void go_down(int x, int lx, int rx) {
    if (rx - lx == 1 || arr[x].num == 0)
        return;
    arr[2 * x + 1].num = arr[2 * x + 2].num = arr[x].num;
    arr[2 * x + 1].ans = arr[2 * x + 2].ans = ((!prime[arr[x].num]) ? (rx - lx) / 2 : 0);
    arr[x].num = 0;
}

void build(vector<ll> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        if (lx < a.size()) {
            arr[x].num = a[lx];
            arr[x].ans = !prime[a[lx]];
        }
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    arr[x].ans = arr[2 * x + 1].ans + arr[2 * x + 2].ans;
}

void build(vector<ll> &a) {
    build(a, 0, 0, siz);
}

void update(int l, int r, int v, int x, int lx, int rx) {
    go_down(x, lx, rx);
    if (lx >= r || rx <= l)
        return;
    if (lx >= l && rx <= r) {
        arr[x].num = v;
        arr[x].ans = ((!prime[v]) ? rx - lx : 0);
        return;
    }
    int m = (lx + rx) >> 1;
    update(l, r, v, 2 * x + 1, lx, m);
    update(l, r, v, 2 * x + 2, m, rx);
    arr[x].ans = arr[2 * x + 1].ans + arr[2 * x + 2].ans;
}

void update(int l, int r, int v) {
    update(l, r, v, 0, 0, siz);
}

ll query(int l, int r, int x, int lx, int rx) {
    go_down(x, lx, rx);
    if (lx >= r || rx <= l)
        return 0ll;
    if (lx >= l && rx <= r)
        return arr[x].ans;
    int m = (lx + rx) >> 1;
    ll s1 = query(l, r, 2 * x + 1, lx, m);
    ll s2 = query(l, r, 2 * x + 2, m, rx);
    return s1 + s2;
}

ll query(int l, int r) {
    return query(l, r, 0, 0, siz);
}

void GREEN() {
    cout << "Case " << t << ":" << el;
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    init(n);
    build(a);
    for (int i = 0; i < q; ++i) {
        int op, l, r, v;
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
    seive();
    int tc = 1;
    cin >> tc;
    while (tc--) {
        t++;
        GREEN();
    }
}
