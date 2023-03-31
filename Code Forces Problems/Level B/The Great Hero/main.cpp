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
    ll b, n;
    double a;
    cin >> a >> b >> n;
    vector<pair<ll, ll>> monster(n);
    for (int i = 0; i < n; ++i) cin >> monster[i].fi;
    for (int i = 0; i < n; ++i) cin >> monster[i].se;
    sort(all(monster));
    ll i = 0;
    while (b > 0) {
        if (i == monster.size()) {
            cout << "YES" << el;
            return;
        }
        b -= monster[i].fi * ceil(monster[i++].se / a);
    }
    if (i < monster.size())cout << "NO" << el;
    else {
        b += monster.back().fi;
        if (b <= 0) cout << "NO" << el;
        else cout << "YES" << el;
    }

}

int main() {
    IOS
    PREC
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GO();
    }
}
