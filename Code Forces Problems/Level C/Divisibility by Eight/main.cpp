
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
    string s;
    cin >> s;
    vector<string> divs;
    if (s.find('0') != s.npos) {
        cout << "YES" << el << '0';
        return 0;
    } else if (s.find('8') != s.npos) {
        cout << "YES" << el << '8';
        return 0;
    }
    for (int i = 1; i <= 125; ++i) divs.pb(to_string(8 * i));

    s = "0" + s;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            for (int k = j + 1; k < s.size(); ++k) {
                string x;
                if (s[i] != '0')x.pb(s[i]);
                x.pb(s[j]);
                x.pb(s[k]);
                auto it = find(divs.begin(), divs.end(), x);
                if (it != divs.end()) {
                    cout << "YES" << el << *it;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}
