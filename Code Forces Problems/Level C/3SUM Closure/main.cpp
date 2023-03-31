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
    ll n;
    cin >> n;
    map<ll, bool> exist;
    vector<ll> num(n), nonZero;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        exist[num[i]] = true;
        if (num[i]) nonZero.pb(num[i]);
    }
    sort(all(num));
    if (!exist[num[0] + num[1] + num[2]] || !exist[num[n - 3] + num[n - 1] + num[n - 2]]) cout << "NO" << el;
    else {
        if (nonZero.size() == 2) {
            if (exist[nonZero[0] + nonZero[1]]) cout << "YES" << el;
            else cout << "NO" << el;
        } else {
            for (int i = 0; i < nonZero.size(); ++i) {
                for (int j = i + 1; j < nonZero.size(); ++j) {
                    for (int k = j + 1; k < nonZero.size(); ++k) {
                        if (!exist[nonZero[i] + nonZero[j] + nonZero[k]]) {
                            cout << "NO" << el;
                            return;
                        }
                    }
                }
            }
            cout << "YES" << el;
        }
    }
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
