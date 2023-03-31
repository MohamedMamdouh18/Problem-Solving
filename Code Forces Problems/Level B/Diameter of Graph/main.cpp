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
vector<vector<int>> adj;
vector<bool> visited;

void GREEN() {
    ll n, m, k;
    cin >> n >> m >> k;
    k--;
    if (n == 1 && m == 0) {
        if (k > 0)cout << "YES" << el;
        else cout << "NO" << el;
    } else if (m > (((n * (n - 1))) / 2) || m < n - 1 || k <= 1) cout << "NO" << el;
    else {
        if (m == ((n * (n - 1)) / 2) && k >= 2)cout << "YES" << el;
        else if(m >= n -1 && m < ((n * (n - 1)) / 2) && k >= 3) cout << "YES" << el;
        else cout << "NO" << el;
    }
}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
