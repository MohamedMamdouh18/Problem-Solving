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
int n, m, a, b, c, x, y;
vector<vector<int>> adj;

void GREEN() {
    string s ;
    char smaller = 'z';
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if(i == 0) cout << "Mike" << el;
        else if(s[i] <= smaller){
            smaller = s[i] ;
            cout << "Mike" << el;
        }else cout << "Ann" << el ;
        smaller = min(smaller , s[i]) ;
    }
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
