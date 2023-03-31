#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    int n;
    cin >> n;
    vector<int> days(7);
    for (int i = 0; i < 7; ++i) cin >> days[i];
    int i = 0;
    while (n > 0) {
        n -= days[i];
        i = (i + 1) % 7;
    }
    cout << (i == 0 ? 7 : i);
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
