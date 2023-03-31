#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, k, x, pass;
    cin >> n >> k;
    k -- ;
    vector<int> scores;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        scores.pb(x);
        if (i == k) pass = x;
    }
    if (pass == 0) pass++;
    sort(scores.begin(), scores.end());
    cout << n - (lower_bound(scores.begin(), scores.end(), pass) - scores.begin());
}
