#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 101, M = 20, INF = 1e-18;

void LIGHT_BLUE() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    set<char> unique;
    for (char i: s)
        unique.insert(i);
    int goal = unique.size();

    int r = 0, ans = INT_MAX, cur = 0;
    vector<int> freq((int) 'z' + 1);
    for (int l = 0; l < n; ++l) {
        while (cur < goal && r < n) {
            if (freq[s[r] - 'A'] == 0)
                cur++;
            freq[s[r] - 'A']++;
            r++;
        }
        if (r == n && cur < goal)
            break;
        ans = min(ans, r - l);
        if (freq[s[l] - 'A'] == 1)
            cur--;
        freq[s[l] - 'A']--;

    }
    cout << ans;
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        LIGHT_BLUE();
    }
}
