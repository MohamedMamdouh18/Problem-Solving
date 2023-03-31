#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int sub = INT_MAX;

void make_crnt(vector<int> &perm, vector<vector<int>> &original, vector<int> &nextShape) {
    for (int i = 0; i < nextShape.size(); ++i) {
        int x = 0;
        for (int j = 0; j < perm.size(); ++j) {
            x += original[i][perm[j]] * pow(10, j);
        }
        nextShape[i] = x;
    }
}

void calc(vector<int> &nextShape) {
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < nextShape.size(); ++i) {
        mn = min(mn, nextShape[i]);
        mx = max(mx, nextShape[i]);
    }
    sub = min(sub, mx - mn);
}

int main() {
    IOS
    int n, k;
    cin >> n >> k;

    vector<vector<int>> original(n);
    vector<int> perm;
    vector<int> nextShape(n);
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        for (int j = 0; j < k; ++j) original[i].pb(x[j] - '0');

    }
    for (int i = 0; i < k; ++i) perm.pb(i);

    do {
        make_crnt(perm, original, nextShape);
        calc(nextShape);

    } while (next_permutation(perm.begin(), perm.end()));

    cout << sub;
}
