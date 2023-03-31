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
const ll mod = 1e9 + 7, N = 2e7 + 25;

void GREEN() {
    int n, current = 9;
    cin >> n;
    if(n == 1) cout << 9 ;
    else{
        cout << 98 ;
        n -= 2;
        while (n--) {
            cout << current;
            current = ((current == 9) ? 0 : current + 1);
        }
    }

    cout << el ;
}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
