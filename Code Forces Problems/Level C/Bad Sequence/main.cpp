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
    int n, sum = 0;
    string s;
    cin >> n;
    cin >> s;

    for (auto ch: s) {
        if (ch == '(') sum++;
        else sum--;
        if (sum < -1) {
            cout << "NO" << el;
            return 0;
        }
    }

    cout << (sum == 0 ? "YES" : "NO");
}
