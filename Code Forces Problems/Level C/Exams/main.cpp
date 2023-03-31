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
    int n ;
    cin >> n ;
    vector<pair<int,int>> exam(n) ;
    for (int i = 0; i < n; ++i) cin >> exam[i].fi >> exam[i].se ;
    sort(all(exam)) ;
    int current = min(exam[0].fi,exam[0].se) ;
    for (int i = 1; i < n; ++i) {
        if(exam[i].fi == current || exam[i].se == current) continue;
        else{
            if(exam[i].fi > current && exam[i].se > current) current = min(exam[i].fi,exam[i].se) ;
            else current = max(exam[i].fi,exam[i].se) ;
        }
    }
    cout << current ;
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
