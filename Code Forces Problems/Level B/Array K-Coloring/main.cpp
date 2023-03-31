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
 
int freq[5005];
vector<vector<int>> index(5005);
 
void solve() {
    int n, k, flag = 0;
    cin >> n >> k;
    vector<int> num(n), ans(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        freq[num[i]]++;
        index[num[i]].pb(i);
        if(freq[num[i]] > k) flag = 1 ;
    }
    if (k > n || flag) {
        cout << "NO";
        return;
    }
    int color = 1 ;
    for (int i = 0; i < index.size(); ++i) {
        for (int j = 0; j < k; ++j) {
            if (j >= index[i].size()) break;
            ans[index[i][j]] = color;
            color = color % k + 1 ;
        }
    }
    cout << "YES" << el;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}
 
int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
