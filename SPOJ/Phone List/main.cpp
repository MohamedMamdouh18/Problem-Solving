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
const int mod = 1e9 + 7, N = 1e6 + 50, M = 23, INF = INT_MAX;
const double eps = 1e-6;

struct Node {
    Node *nxt[10];
    bool is_end;

    Node() {
        is_end = false;
        memset(nxt, 0, sizeof nxt);
    }
} *root;

bool insert(const string &s) {
    Node *cur = root;
    for (char i: s) {
        int idx = i - '0';
        if (!cur->nxt[idx])
            cur->nxt[idx] = new Node();
        cur = cur->nxt[idx];
        if (cur->is_end)
            return false;
    }
    return cur->is_end = true;
}

bool cmp(const string &a, const string &b) {
    return a.size() < b.size();
}

void GREEN() {
    root = new Node() ;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a), cmp);
    for (const auto& s: a) {
        if (!insert(s)) {
            cout << "NO" << el;
            return;
        }
    }
    cout << "YES" << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
