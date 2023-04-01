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
    Node *nxt[26];
    vector<int> words;

    Node() {
        memset(nxt, 0, sizeof nxt);
    }
} *root;

void insert(int word_idx, const string &s) {
    Node *cur = root;
    for (int i = 0; i < (int) s.size(); i++) {
        int idx = s[i] - 'a';
        if (!cur->nxt[idx])
            cur->nxt[idx] = new Node();
        cur = cur->nxt[idx];
        if (i != (int) s.size() - 1)
            cur->words.pb(word_idx);
    }
}

vector<int> find_prefix(const string &prefix) {
    Node *cur = root;
    vector<int> empty;
    for (char i: prefix) {
        int idx = i - 'a';
        if (!cur->nxt[idx])
            return empty;
        cur = cur->nxt[idx];
    }
    return cur->words;
}

void GREEN() {
    root = new Node();
    int n, q;
    cin >> n;
    vector<string> words;
    set<string> exist;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (exist.count(s) || s.empty()) continue;
        exist.insert(s);
        words.pb(s);
    }
    sort(all(words));
    for (int i = 0; i < (int) words.size(); ++i) insert(i, words[i]);

    cin >> q;
    for (int i = 1; i <= q; ++i) {
        string s;
        cin >> s;
        auto ans = find_prefix(s);
        cout << "Case #" << i << ":" << el;
        if (ans.empty()) cout << "No match." << el;
        else {
            for (int j = 0; j < ans.size(); ++j)
                cout << words[ans[j]] << el;
        }
    }

}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
