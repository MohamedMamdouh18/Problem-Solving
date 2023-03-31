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

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

void GREEN() {
    ll n;
    cin >> n;
    ll x , i = 0;
    while (true) {
        int sum = 0;
        x = n + i++;
        while (x > 0) sum += x % 10, x /= 10;
        if (gcd((n + i - 1), sum) > 1) {
            cout << (n + i - 1) << el;
            return;
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
