#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e5 + 1;
int freq[N];

void GREEN() {
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    if (count(all(num), x) == 0) num.pb(x), ans++;
    sort(all(num));
    while (num[(num.size() + 1) / 2 - 1] != x) {
        if (num[(num.size() + 1) / 2 - 1] > x) num.insert(num.begin(), 0);
        else num.pb(1e6);
        ans++;
    }
    cout << ans;

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
