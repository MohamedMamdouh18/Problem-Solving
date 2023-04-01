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

struct node {
    int cnt[3], add;

    node() {
        memset(cnt, 0, sizeof cnt);
        cnt[0] = 1;
        add = 0;
    }
}emt;

int siz;
vector<node> arr;

void init(int n) {
    siz = 1;
    arr.clear();
    while (siz < n) siz *= 2;
    arr.resize(2 * siz);
}

void go_down(int x, int lx, int rx) {
    if (rx - lx == 1 || arr[x].add % 3 == 0)
        return;
    if (arr[x].add % 3 == 1) {
        int tmp = arr[2 * x + 1].cnt[2];
        arr[2 * x + 1].cnt[2] = arr[2 * x + 1].cnt[1];
        arr[2 * x + 1].cnt[1] = arr[2 * x + 1].cnt[0];
        arr[2 * x + 1].cnt[0] = tmp;

        tmp = arr[2 * x + 2].cnt[2];
        arr[2 * x + 2].cnt[2] = arr[2 * x + 2].cnt[1];
        arr[2 * x + 2].cnt[1] = arr[2 * x + 2].cnt[0];
        arr[2 * x + 2].cnt[0] = tmp;
    } else if (arr[x].add % 3 == 2) {
        int tmp = arr[2 * x + 1].cnt[2];
        arr[2 * x + 1].cnt[2] = arr[2 * x + 1].cnt[0];
        arr[2 * x + 1].cnt[0] = arr[2 * x + 1].cnt[1];
        arr[2 * x + 1].cnt[1] = tmp;

        tmp = arr[2 * x + 2].cnt[2];
        arr[2 * x + 2].cnt[2] = arr[2 * x + 2].cnt[0];
        arr[2 * x + 2].cnt[0] = arr[2 * x + 2].cnt[1];
        arr[2 * x + 2].cnt[1] = tmp;
    }
    arr[2 * x + 1].add += arr[x].add;
    arr[2 * x + 2].add += arr[x].add;
    arr[x].add = 0;
}

node merge(node a, node b) {
    node ans;
    for (int i = 0; i < 3; ++i) {
        ans.cnt[i] = a.cnt[i] + b.cnt[i];
    }
    return ans;
}

void build(int n ,int x , int lx , int rx){
    if(lx >= n || rx - lx == 1)
        return;
    int m = (lx + rx) >> 1;
    build(n, 2 * x + 1, lx, m);
    build(n, 2 * x + 2, m, rx);
    arr[x] = merge(arr[2 * x + 1], arr[2 * x + 2]);
}

void build(int n){
    build(n,0 , 0 , siz) ;
}

void update(int l, int r, int x, int lx, int rx) {
    go_down(x, lx, rx);
    if (lx >= r || rx <= l)
        return;
    if (lx >= l && rx <= r) {
        arr[x].add++;
        int tmp = arr[x].cnt[2];
        arr[x].cnt[2] = arr[x].cnt[1];
        arr[x].cnt[1] = arr[x].cnt[0];
        arr[x].cnt[0] = tmp;
        return;
    }
    int m = (lx + rx) >> 1;
    update(l, r, 2 * x + 1, lx, m);
    update(l, r, 2 * x + 2, m, rx);
    arr[x] = merge(arr[2 * x + 1], arr[2 * x + 2]);
}

void update(int l, int r) {
    update(l, r, 0, 0, siz);
}

node query(int l, int r, int x, int lx, int rx) {
    go_down(x, lx, rx);
    if (lx >= r || rx <= l)
        return emt;
    if (lx >= l && rx <= r)
        return arr[x];
    int m = (lx + rx) >> 1;
    node s1 = query(l, r, 2 * x + 1, lx, m);
    node s2 = query(l, r, 2 * x + 2, m, rx);
    return merge(s1, s2);
}

ll query(int l, int r) {
    return query(l, r, 0, 0, siz).cnt[0];
}

void GREEN() {
    emt.cnt[0] = 0 ;
    int n, q;
    cin >> n >> q;
    init(n);
    build(n) ;
    for (int i = 0; i < q; ++i) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op)
            cout << query(l, r + 1)<< el ;
        else
            update(l, r + 1);
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
