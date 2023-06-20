#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1000406, M = 20, INF = LONG_LONG_MAX;

void LIGHT_BLUE() {
    int n, ans = 0;
    cin >> n;
    vector<int> weight(n), freq(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
        freq[weight[i]]++;
    }
    for (int i = 2; i <= 2 * n; ++i) {
        vector<int> used(n + 1);
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if(i <= weight[j] || used[weight[j]] >= freq[weight[j]])
                continue;
            int need = abs(i - weight[j]);
            used[weight[j]]++;
            if (need <= n && used[need] < freq[need]) {
                cur++;
                used[need]++, used[weight[j]]++;
            }
            used[weight[j]]--;
        }
        ans = max(ans, cur);
    }
    cout << ans << el;
}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        LIGHT_BLUE();
    }
}
