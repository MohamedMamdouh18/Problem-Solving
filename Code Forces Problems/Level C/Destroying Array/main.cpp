#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct item {
    ll seg, pref, suff, sum;
};
int size = 1;
vector<ll> arr;
vector<item> seg_tree;

void init(int n) {
    while (size < n) size *= 2;
    seg_tree.resize(size * 2);
}

item merge(item a, item b) {
    return {max(max(a.seg, b.seg), a.suff + b.pref), max(a.pref, a.sum + b.pref), max(b.suff, b.sum + a.suff),
            a.sum + b.sum};
}

void build(int x, int lx, int rx) {
    if (rx - lx == 1) {
        if (lx < arr.size()) seg_tree[x] = {arr[lx], arr[lx], arr[lx], arr[lx]};
        return;
    }
    int m = (lx + rx) / 2;
    build(2 * x + 1, lx, m);
    build(2 * x + 2, m, rx);
    seg_tree[x] = merge(seg_tree[2 * x + 1], seg_tree[2 * x + 2]);
}

void build() {
    build(0, 0, size);
}

void rem(int i, int x, int lx, int rx) {
    if (rx - lx == 1) {
        seg_tree[x] = {0, 0, 0, -80000000000000LL};
        return;
    }
    int m = (lx + rx) / 2;
    if (i < m) rem(i, 2 * x + 1, lx, m);
    else rem(i, 2 * x + 2, m, rx);
    seg_tree[x] = merge(seg_tree[2 * x + 1], seg_tree[2 * x + 2]);
}

void rem(int i) {
    rem(i, 0, 0, size);
}

int main() {
    IOS
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    init(n);
    build();
    for (int i = 0; i < n; ++i) {
        int proc;
        cin >> proc;
        rem(proc - 1);
        cout << seg_tree[0].seg << endl;
    }
}
