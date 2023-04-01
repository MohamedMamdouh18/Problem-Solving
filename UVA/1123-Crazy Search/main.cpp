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

string s;
int n, k;

struct Node {
    Node *nxt[26];

    Node() {
        memset(nxt, 0, sizeof nxt);
    }
} *root;

bool insert(int start) {
    bool valid = false;
    Node *cur = root;
    for (int i = start; i < start + n; i++) {
        int idx = s[i] - 'a';
        if (!cur->nxt[idx]) {
            cur->nxt[idx] = new Node();
            valid = true;
        }
        cur = cur->nxt[idx];
    }
    return valid;
}

void GREEN() {
    root = new Node();
    cin >> n >> k >> s;
    int ans = 0;
    for (int i = 0; i <= (int) s.size() - n; ++i) {
        ans += insert(i);
    }
    cout << ans << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
        if (tc != 0) cout << el;
    }
}
