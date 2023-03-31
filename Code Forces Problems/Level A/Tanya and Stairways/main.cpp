#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    int n, stair = 0, last, x;
    vector<int> ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (i != 0)
            if (x != last + 1) {
                ans.pb(last);
                stair++;
            }
        last = x;
    }
    stair ++ ;
    ans.pb(last) ;
    cout << stair << el;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";

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
