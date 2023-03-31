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
vector<ll> price;
ll n, k;

bool good(ll add) {
    bool flag = true;
    ll sum = price[0] + add;
    for (int i = 1; i < price.size(); ++i) {
        if (price[i] > sum * k / 100) {
            flag = false;
            break;
        }
        sum += price[i] ;
    }
    return flag;
}

ll binsrch() {
    ll l = 0, r = 1e14;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (good(mid)) r = mid;
        else l = mid+1;
    }
    return l;
}

void GO() {
    cin >> n >> k;
    price.resize(n);
    for (int i = 0; i < n; ++i) cin >> price[i];
    cout << binsrch() << el;
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
