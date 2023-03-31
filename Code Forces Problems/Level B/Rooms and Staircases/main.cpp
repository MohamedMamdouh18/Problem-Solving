#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int first = INT_MAX, last = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            first = min(first, i);
            last = max(last, i);
        }
    }
    if(first == INT_MAX) cout << n << el ;
    else cout << max((last+1) * 2, (n - first) * 2) << el;
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
