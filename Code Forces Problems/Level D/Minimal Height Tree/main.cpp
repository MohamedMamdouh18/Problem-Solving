#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9, N = 2 * 1e5 + 1, INF = LONG_LONG_MAX;
const double eps = 1e-6;
int n, ans = 0;
vector<int> num;

void bfs(){
    int cur = 1 , siz=1;
    queue<int> q;
    q.push(num[0]) ;
    for (ans = 0 ;!q.empty() ; ans ++, siz = q.size()) {
        while (siz --){
            q.pop() ;
            if(cur < num.size())q.push(num[cur++]) ;
            while (cur < num.size() && num[cur] > num[cur-1]) {
                q.push(num[cur]) ;
                cur ++ ;
            }
        }
    }
}

void GREEN() {
    cin >> n;
    num.clear();
    num.resize(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    bfs() ;
    cout << ans-1 << el ;
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
