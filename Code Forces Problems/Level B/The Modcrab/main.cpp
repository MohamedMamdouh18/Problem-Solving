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
ll h1, a1, c1, h2, a2;
ll heal;

bool good(ll moves) {
    ll cur = 0, health = h1, rem = moves - 1;
    while (moves) {
        if (health - rem * a2 > 0 && h2 - a1 * moves <= 0) {
            heal = cur;
            return true;
        }
        moves--, cur++;
        health += c1;
    }
    return false;
}

void GREEN() {
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    ll l = 0, r = 1e5;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (good(mid)) r = mid;
        else l = mid;
    }
    cout << r << el;
    r -= heal;
    while (heal--)cout << "HEAL" << el;
    while (r--)cout << "STRIKE" << el;
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
