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

void GO() {
    int n, m;
    cin >> n >> m;
    vector<int> num(n), pos(m);
    for (int i = 0; i < n; ++i) cin >> num[i];
    for (int i = 0; i < m; ++i) {
        cin >> pos[i];
        pos[i]--;
    }
    sort(all(pos));
    int r = 0, l = 0;
    while (r < pos.size()) {
        l = pos[r];
        while (r < pos.size() - 1 && pos[r] == pos[r + 1] - 1)r++;
        sort(num.begin() + l, num.begin() + pos[r] + 2);
        r++;
    }
    if (is_sorted(all(num))) cout << "YES" << el;
    else cout << "NO" << el;

}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GO();
    }
}
