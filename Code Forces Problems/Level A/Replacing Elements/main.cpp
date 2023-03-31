#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e5;

void GREEN() {
    int n, d;
    cin >> n >> d;
    vector<int> num(n);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        if (num[i] > d) flag = true;
    }
    if (!flag) cout << "YES" << el;
    else {
        sort(all(num));
        if (num[0] + num[1] <= d) cout << "YES" << el;
        else cout << "NO" << el;
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
