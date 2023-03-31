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
    int n , m , ans = 0;
    cin >> n>> m ;
    vector<int> tv(n) ;
    for (int i = 0; i < n; ++i) cin >> tv[i] ;
    sort(all(tv)) ;
    for (int i = 0; i < m; ++i) {
        if(tv[i] < 0) ans -= tv[i] ;
        else break ;
    }
    cout << ans;
}

int main() {
    IOS
    PREC

    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
