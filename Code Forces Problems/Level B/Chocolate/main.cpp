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

void GO() {
    int n, x, first = INT_MAX, last = INT_MIN , count = 1;
    ll ans = 1 ;
    cin >> n;
    bitset<100> arr;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x) {
            first = min(first, i);
            last = max(last, i);
        }
        arr[i] = x;
    }
    if (arr.count() == 0) {
        cout << 0;
        return;
    }
    for (int i = first ; i <= last; ++i) {
        if(arr[i]){
            ans *= count ;
            count = 1 ;
        }else count ++ ;
    }
    cout << ans ;

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
