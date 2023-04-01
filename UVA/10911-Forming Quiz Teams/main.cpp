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
const ll mod = 1e9 + 7, N = 1e5, M = 20, INF = LONG_LONG_MAX;
const double eps = 1e-6;
double dp[N];
bool vis[N] ;
int n , t = 0;
vector<pair<double, double>> house(M);

double solve(int msk, int idx) {
    if (msk == (1 << (2 * n)) - 1) return 0 ;
    if(vis[msk]) return dp[msk] ;
    vis[msk] = true ;
    double ans = INT_MAX;
    for (int i = 0; i < 2 * n; ++i) {
        if(msk & (1 << i) || i == idx) continue;
        int nxt ;
        for (int j = 0; j < 2 * n; ++j) {
            if(msk & (1 << j) || i == j || j == idx) continue;
            nxt = j ;
            break;
        }
        ans = min(ans , solve(msk | (1 << i) | (1 << idx) , nxt) + sqrt(pow(house[idx].fi - house[i].fi,2)
                                                        + pow(house[idx].se - house[i].se,2))) ;
    }
    return dp[msk] = ans ;
}

void GREEN() {
    while (cin >> n && n) {
        t++ ;
        string s;
        memset(vis , false , sizeof vis) ;
        for (int i = 0; i < 2 * n; ++i) {
            cin >> s >> house[i].fi >> house[i].se;
        }
        printf("Case %d: %.2f\n" , t , solve(0,0)) ;
    }
}

int main() {
//    IOS
//    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
