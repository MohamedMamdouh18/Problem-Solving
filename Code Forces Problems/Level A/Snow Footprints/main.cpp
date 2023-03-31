#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e5 + 1;
int freq[N];

void GREEN() {
    int n, start = -1, end = -1;
    cin >> n;
    string s;
    cin >> s;
    int ls = count(all(s), 'L'), rs = count(all(s), 'R');
    if (ls == 0) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'R' && start == -1) start = i + 1;
            if ((i == n - 1 || s[i + 1] == '.') && s[i] == 'R')end = i + 2;
        }
    } else if (rs == 0) {
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == 'L' && start == -1) start = i + 1;
            if ((i == 0 || s[i - 1] == '.') && s[i] == 'L')end = i;
        }
    } else {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'R' && start == -1) start = i + 1;
            if (s[i] == 'R')end = i + 1;
        }
    }
    cout << start << " " << end;
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
