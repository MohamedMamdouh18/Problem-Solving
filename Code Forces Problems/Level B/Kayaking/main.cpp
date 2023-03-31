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
const ll mod = 1e9 + 7, N = 1e5 + 1;
int freq[N];

void GREEN() {
    int n, ans = INT_MAX;
    cin >> n;
    vector<int> w(2 * n);
    for (int i = 0; i < 2 * n; ++i) cin >> w[i];
    sort(all(w));
    for (int i = 0; i < w.size(); ++i) {
        for (int j = i + 1; j < w.size(); ++j) {
            vector<int> dup (w) ;
            dup.erase(dup.begin() + i) ;
            dup.erase(dup.begin() + j-1) ;
            int current = 0;
            for (int k = 0; k < dup.size()-1; k+=2) current += dup[k + 1] - dup[k];
            ans = min(ans, current);
        }
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
