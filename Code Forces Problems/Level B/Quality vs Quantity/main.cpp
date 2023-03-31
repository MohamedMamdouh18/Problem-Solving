#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    ll n;
    cin >> n;
    vector<ll> num(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    sort(all(num));
    ll blueSum = num[0] + num[1], redSum = num[num.size() - 1], bl = 2, rd = num.size() - 2;
    while (rd > bl) {
        if (blueSum < redSum) {
            cout << "YES" << el ;
            return;
        }
        blueSum += num[bl++];
        redSum += num[rd--];
    }
    if (blueSum < redSum) cout << "YES" << el ;
    else cout << "NO" << el ;

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
