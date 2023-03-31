#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;

bool isPalindrome(string s, int end) {
    for (int i = 0; i < end; ++i) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}

void GREEN() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (k == 0) {
        cout << "YES" << el;
        return;
    }
    if (n & 1) cout << ((isPalindrome(s, k)) ? "YES" : "NO") << el;
    else cout << ((isPalindrome(s, k) && k < n / 2) ? "YES" : "NO") << el;


}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
