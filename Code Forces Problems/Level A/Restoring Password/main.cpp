#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    string pass, s, ans;
    cin >> pass;
    map<string, string> encode;
    for (int i = 0; i < 10; ++i) {
        cin >> s;
        encode[s] = to_string(i);
    }
    for (int i = 0; i < 8; ++i) {
        s = pass.substr(i * 10, 10);
        ans += encode[s];
    }

    cout << ans;
}
