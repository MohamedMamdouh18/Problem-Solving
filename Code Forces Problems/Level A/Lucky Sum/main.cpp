#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll> lucky;
ll sum = 0;

void addNumber(ll current) {
    if (current > 1e10) return;
    lucky.pb(current);
    addNumber(10 * current + 7);
    addNumber(10 * current + 4);
}

void CalcLucky(ll current, ll final, ll last) {
    ll close = *lower_bound(lucky.begin(), lucky.end(), current + 1);
    if (close >= final) {
        sum += close * (final - last);
        return;
    }
    sum += close * (close - last);
    CalcLucky(close, final, close);
}

int main() {
    IOS
    ll l, r;
    cin >> l >> r;
    addNumber(4);
    addNumber(7);
    sort(lucky.begin(), lucky.end());
    ll close = *lower_bound(lucky.begin(), lucky.end(), l);

    if (close > r) {
        sum += close * (r - l + 1);
        cout << sum;
        return 0;
    }

    sum += close * (close - l + 1);
    CalcLucky(close, r, close);
    cout << sum;
}
