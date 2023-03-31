#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e6;
 
void GREEN() {
    int n, k, x, l, r, firstInd;
    cin >> n >> k;
    map<int, int> first, last;
    map<int, bool> occur;
    cin >> x;
    first[x] = 0, firstInd = x, occur[x] = true;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (first[x] == 0 && x != firstInd) first[x] = i;
        last[x] = i;
        occur[x] = true;
    }
    for (int i = 0; i < k; ++i) {
        cin >> l >> r;
        if (first[l] < last[r] && occur[l] && occur[r])cout << "YES" << el;
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
