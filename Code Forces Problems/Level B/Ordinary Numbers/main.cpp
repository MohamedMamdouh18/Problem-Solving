#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e6;
vector<int> ordinary;

void GREEN() {
    int n, count = 0, ans = 0, first;
    cin >> n;
    vector<int> num;
    int x = n;
    while (x > 0) {
        if (x / 10 == 0)first = x;
        num.pb(x % 10);
        count++, x /= 10;
    }
    ans += ordinary[count - 1];
    ans += ((n / pow(10, count - 1)) - 1);
    x = n;
    reverse(all(num)) ;
    for (int i = 0; i < num.size(); ++i) {
        if(num[i] < first){
            cout << ans << el;
            return;
        }else if(num[i] > first) break;
    }
    cout << ans + 1 << el;

}

int main() {
    IOS
    PREC

    ordinary.resize(10);
    ordinary[0] = 0;
    for (int i = 1; i < 10; ++i) ordinary[i] = ordinary[i - 1] + 9;

    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
