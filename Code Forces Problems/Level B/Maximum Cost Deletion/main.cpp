#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    ll n, a, b, ans = 0;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    ans += s.size() * a;
    if (b < 0) {
        ll zero_seg = 0, one_seg = 0, last = 0, count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0)last = s[i] - '0';
            else if (s[i] - '0') {
                if (last) count++;
                else {
                    zero_seg++;
                    last = 1;
                    count = 1;
                }
            } else {
                if (last) {
                    one_seg++;
                    last = 0;
                    count = 1;
                } else count++;
            }
        }
        if (count > 0) {
            if (last) one_seg++;
            else zero_seg++;
        }
        ans += (min(zero_seg, one_seg)+1) * b ;
        cout << ans  << el;
    } else {
        ans += s.size() * b ;
        cout << ans << el;
    }
}

int main() {
    IOS
    PREC

    int tc = 1;
    cin >> tc;
    while (tc--) {
        GO();
    }
}
