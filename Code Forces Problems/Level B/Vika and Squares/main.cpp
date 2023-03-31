
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    ll n, x, mn, first, last, plus = 0;
    cin >> n;
    set<pair<ll, ll>> paint;
    vector<ll> minpaint;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        paint.insert({x, i});
    }
    mn = paint.begin()->fi;
    first = paint.begin()->se;

    for (auto item: paint) {
        if (item.fi > mn) break;
        minpaint.pb(item.se + 1);
        last = item.se + 1;
    }

    for (int i = 1; i < minpaint.size(); ++i) plus = max(plus, minpaint[i] - minpaint[i - 1] - 1);

    if (minpaint.size() == 1) plus = n - 1;

    ll ans = n * mn + max(n - last + first, plus);
    cout << ans;
}
