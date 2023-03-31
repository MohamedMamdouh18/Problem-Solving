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
    int n, m, x, y, q, op, ans = 0;
    cin >> n >> m;
    vector<int> edge(n+1) ;
    vector<int> weak(n+1) ;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y ;
        edge[x] ++ , edge[y]++ ;
        if(x > y) weak[x] ++ ;
        else weak[y] ++ ;
    }
    for (int i = 1; i < n + 1; ++i) if(weak[i] == edge[i]) ans ++ ;
    int count = ans ;
    cin >> q ;
    while (q--){
        cin >> op ;
        if(op == 3) cout << count << el ;
        else if(op == 1){
            cin >> x >> y ;
            edge[x] ++ , edge[y]++ ;
            if(x > y) {
                weak[x] ++ ;
                if(weak[y] == edge[y] - 1) count -- ;
            }
            else {
                weak[y] ++ ;
                if(weak[x] == edge[x] - 1) count -- ;
            }
        }else{
            cin >> x >> y ;
            edge[x] -- , edge[y]-- ;
            if(x > y) {
                weak[x] -- ;
                if(weak[y] == edge[y]) count ++ ;
            }
            else {
                weak[y] -- ;
                if(weak[x] == edge[x]) count ++ ;
            }
        }
    }
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
