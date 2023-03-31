#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int ans = 0;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        ans += pow(2, i);
    }

    bitset<10> rank;
    for (int i = 0; i < s.size(); ++i) {
        if (s[s.size() - i - 1] == '4') rank.set(i, false);
        else rank.set(i, true);
    }

    ans += rank.to_ulong() + 1;
    cout << ans;
}
