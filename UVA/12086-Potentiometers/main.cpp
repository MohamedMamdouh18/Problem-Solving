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
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = LONG_LONG_MAX;

int siz;
vector<ll> arr;

void init(int n) {
    siz = 1;
    arr.clear();
    while (siz < n) siz *= 2;
    arr.assign(2 * siz, 0ll);
}

void build(vector<ll> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        if (lx < a.size())
            arr[x] = a[lx];
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    arr[x] = arr[2 * x + 1] + arr[2 * x + 2];
}

void build(vector<ll> &a) {
    build(a, 0, 0, siz);
}

void update(int i, ll v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        arr[x] = v;
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m)
        update(i, v, 2 * x + 1, lx, m);
    else
        update(i, v, 2 * x + 2, m, rx);
    arr[x] = arr[2 * x + 1] + arr[2 * x + 2];
}

void update(int i, ll v) {
    update(i, v, 0, 0, siz);
}

ll sum(int l, int r, int x, int lx, int rx) {
    if (lx >= r || rx <= l)
        return 0ll;
    if (lx >= l && rx <= r)
        return arr[x];
    int m = (lx + rx) >> 1;
    ll s1 = sum(l, r, 2 * x + 1, lx, m);
    ll s2 = sum(l, r, 2 * x + 2, m, rx);
    return s1 + s2;
}

ll sum(int l, int r) {
    return sum(l, r, 0, 0, siz);
}

void GREEN() {
    int n, t = 1;
    while (cin >> n && n) {
        if(t != 1)
            cout << el ;
        cout << "Case " << t << ":" << el;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        init(n);
        build(a);
        string op;
        cin >> op;
        while (op != "END") {
            int x, y;
            cin >> x >> y;
            if (op == "S")
                update(x - 1, y);
            else
                cout << sum(x - 1, y) << el;
            cin >> op;
        }
        t++;
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
