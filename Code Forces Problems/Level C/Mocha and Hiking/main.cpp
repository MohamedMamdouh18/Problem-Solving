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
    int n, last = 0, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (!x) last = i;
    }
    for (int i = 1; i <= last; ++i) cout << i << " ";
    cout << n + 1 << " ";
    for (int i = last + 1; i <= n; ++i) cout << i << " ";
    cout << el;
 
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
