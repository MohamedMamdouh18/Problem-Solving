#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define llm LONG_LONG_MAX
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct item {
    int complete = 0;
    int open = 0;
    int close = 0;
};

vector<item> arr(2097152);
string s;

item merge(item a, item b) {
    int complete = min(a.open, b.close);
    return {a.complete + b.complete + complete, a.open - complete + b.open, b.close - complete + a.close};
}

void build(int x, int lx, int rx) {
    if (rx - lx == 1) {
        if (lx < s.size()) {
            if (s[lx] == '(') arr[x].open++;
            else arr[x].close++;
        }
        return;
    }
    int m = (lx + rx) / 2;
    build(2 * x + 1, lx, m);
    build(2 * x + 2, m, rx);
    arr[x] = merge(arr[x * 2 + 1], arr[x * 2 + 2]);
}

void build() {
    build(0, 0, 2097152 / 2);
}

item calc(int l, int r, int x, int lx, int rx) {
    if (lx >= r || rx <= l) return {0, 0, 0};
    if (lx >= l && rx <= r) return arr[x];

    int m = (lx + rx) / 2;
    item s1 = calc(l, r, 2 * x + 1, lx, m);
    item s2 = calc(l, r, 2 * x + 2, m, rx);
    return merge(s1, s2);
}

item calc(int l, int r) {
    return calc(l, r, 0, 0, 2097152 / 2);
}

int main() {
    IOS
    int m;
    cin >> s;
    build();
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << calc(l - 1, r).complete * 2 << endl;
    }
}
