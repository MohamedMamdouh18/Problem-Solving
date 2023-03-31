#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool valid(ll x, ll k, ll n) {
    return ((k * (k + 1) / 2) - (x * (x - 1) / 2) - (k - x )) >= n;
}

int main() {
    IOS
    ll n, k;
    cin >> n >> k;

    ll l = 2, r = k+1;
    while (r > l + 1) {
        ll mid = (l + r) / 2;
        if (valid(mid, k, n)) l = mid;
        else r = mid;
    }

    if(n == 1) cout << 0 ;
    else if (l == 2 && (k * (k + 1) / 2) - 1 - (k - l) < n) cout << -1;
    else cout << k - l + 1;
}
