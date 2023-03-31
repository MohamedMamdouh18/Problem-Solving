#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll gcd(ll x, ll y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}
 
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> num(n);
        for (auto &item: num) cin >> item;
        if (n < 3) num.pb(num[0]);
        if (n < 4) num.pb(num[1]);
 
        ll gcd1 = gcd(num[0], num[2]);
        ll gcd2 = gcd(num[1], num[3]);
 
        for (int i = 4; i < num.size(); i += 2) {
            gcd1 = gcd(gcd1, num[i]);
        }
        for (int i = 5; i < num.size(); i += 2) {
            gcd2 = gcd(gcd2, num[i]);
        }
 
        int valid1 = 0, valid2 = 0;
 
        if (gcd1 != 1) valid1 = 1;
        if (gcd2 != 1) valid2 = 1;
 
        for (int i = 0; i < num.size(); i++) {
            if (i & 1) {
                if (num[i] % gcd1 == 0) valid1 = 0;
            } else {
                if (num[i] % gcd2 == 0) valid2 = 0;
            }
        }
 
        if (valid1) cout << gcd1 << el;
        else if (valid2) cout << gcd2 << el;
        else cout << 0 << el;
    }
