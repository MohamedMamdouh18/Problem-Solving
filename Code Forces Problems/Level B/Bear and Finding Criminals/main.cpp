#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, a, ans = 0;
    cin >> n >> a;
    a--;
    vector<int> city(n);
    for (int i = 0; i < n; i++) cin >> city[i];
    int dist = 1, right = 0, left = 0;
    ans += city[a];
    while (a - dist >= 0 || dist + a < n) {
        if (a - dist >= 0 && city[a - dist]) left = 1;
        else left = 0;
        if (a - dist < 0) ans += city[a + dist];

        if (dist + a < n && city[a + dist]) right = 1;
        else right = 0;
        if (dist + a >= n) ans += city[a - dist];

        ans += (right && left) * 2;
        dist++;
    }
    cout << ans;
}
