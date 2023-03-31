#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    int n, lower = -2e9, upper = 2e9;
    cin >> n;
    while (n--) {
        string op, ans;
        int x;
        cin >> op >> x >> ans;
        if (op == "<") {
            if (ans == "Y") upper = min(x - 1, upper);
            else lower = max(x, lower);
        } else if (op == "<=") {
            if (ans == "Y") upper = min(x, upper);
            else lower = max(x + 1, lower);
        } else if (op == ">") {
            if (ans == "Y") lower = max(x + 1, lower);
            else upper = min(x, upper);
        } else if (op == ">=") {
            if (ans == "Y") lower = max(x, lower);
            else upper = min(x - 1, upper);
        }
    }
    if(lower > upper) cout << "Impossible" ;
    else cout << lower ;
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
