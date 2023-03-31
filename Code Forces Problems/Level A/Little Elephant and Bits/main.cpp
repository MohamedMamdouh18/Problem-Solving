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
    string s;
    cin >> s;
    int del = s.size() + 1;
    for (int i = 0; i < s.size(); ++i) if (s[i] == '0') del = min(i, del);
    if (del == s.size() + 1) cout << s.substr(0, s.size() - 1);
    else {
        for (int i = 0; i < s.size(); ++i) if (i != del) cout << s[i];
    }
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
