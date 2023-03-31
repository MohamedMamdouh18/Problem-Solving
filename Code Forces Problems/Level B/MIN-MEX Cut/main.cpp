#include <bits/stdc++.h>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
 
        int ans = 0;
        s.erase(unique(s.begin(), s.end()), s.end());
        for (auto ch: s) {
            if (ch == '0') ans++;
        }
        cout << min(2, ans) << "\n";
 
    }
}
