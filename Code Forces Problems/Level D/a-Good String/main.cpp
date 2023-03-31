#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define all(a) a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
string s;

int calc(string half, char fetch) {
    int width = half.size();
    if (width == 1) return half[0] != fetch;
    
    string s1 = half.substr(0, width / 2), s2 = half.substr(width / 2, width);
    int cnt1 = count(s1.begin(), s1.end(), fetch), cnt2 = count(s2.begin(), s2.end(), fetch);

    int ans1 = width / 2 - cnt2 + calc(s1, fetch + 1);
    int ans2 = width / 2 - cnt1 + calc(s2, fetch + 1);
    return min(ans1, ans2);
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        if (n == 1) {
            cout << ((s == "a") ? 0 : 1) << el;
            continue;
        }

        cout << calc(s, 'a') << el;
    }
}
