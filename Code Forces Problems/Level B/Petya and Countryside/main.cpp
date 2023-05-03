#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 110, M = 20, INF = LONG_LONG_MAX;

void GREEN() {
    int n , ans = 0;
    cin >> n ;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i] ;
    }
    for (int i = 0; i < n; ++i) {
        int cur = 0 , mini = num[i];
        for (int j = i-1; j >=0 ; --j) {
            if(num[j] > mini)
                break;
            cur ++ ;
            mini = min(mini, num[j]);
        }
        mini = num[i];
        for (int j = i+1; j < n ; ++j) {
            if(num[j] > mini)
                break;
            cur ++ ;
            mini = min(mini, num[j]);
        }
        ans = max(ans, cur);
    }
    cout << ans + 1 ;
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
