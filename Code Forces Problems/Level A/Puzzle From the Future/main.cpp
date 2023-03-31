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
    int n;
    string s, out = "1";
    cin >> n >> s;
    int d = 1 + s[0] - '0';
    for (int i = 1; i < n; ++i) {
        if (d == 2) {
            d = 1;
            if (s[i] - '0' == 0) out.append("1");
            else out.append("0");
        } else if (d == 1) {
            if (s[i] - '0' == 0) {
                d = 0;
                out.append("0");
            } else {
                d = 2;
                out.append("1");
            }
        } else if (d == 0) {
            if (s[i] - '0' == 0) d = 1;
            else d = 2;
            out.append("1");
        }
    }
    cout << out << el ;
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
