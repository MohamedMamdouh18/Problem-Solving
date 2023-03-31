#include <bits/stdc++.h>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        string s1, s2, s;
        int x;
        cin >> x;
        cin >> s1 >> s2;
 
        int ans = 0;
 
        for (int i = 0; i < s1.size(); ++i) {
            if ((s1[i] + s2[i] - 2 * '0') == 0) s += '1';
            else if ((s1[i] + s2[i] - 2 * '0') == 1) s += '2';
            else s += '0';
        }
 
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '2') ans += 2;
            else if ((s[i] == '0' && s[i + 1] == '1') || s[i + 1] == '0' && s[i] == '1') {
                ans += 2;
                i++;
            } else ans += s[i] - '0';
        }
 
        cout << ans << "\n";
 
    }
}
