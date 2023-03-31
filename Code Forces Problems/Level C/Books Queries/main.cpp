#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void solve() {
    int n, left = 0, item = 0;
    map<int, int> index;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id;
        char op;
        cin >> op >> id;
        if (op == 'L') {
            if (i == 0) index[id] = 0;
            else {
                left++;
                index[id] = -left;
            }
            item++;
        } else if (op == 'R') {
            index[id] = item - left;
            item++;
        } else {
            int ind = index[id] + left;
            cout << min(item - ind - 1, ind) << el;
        }
    }

}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
