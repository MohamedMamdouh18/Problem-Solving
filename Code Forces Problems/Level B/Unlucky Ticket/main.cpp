#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, less = 0, more = 0;
    char x;
    string first, second;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        first.pb(x);
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        second.pb(x);
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    for (int i = 0; i < n; ++i) {
        if (first[i] > second[i]) more++;
        if (first[i] < second[i]) less++;
    }

    if (less == n || more == n) cout << "YES";
    else cout << "NO";
}
