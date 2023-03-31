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

vector<pair<ll, ll>> factorize(ll n) {
    vector<pair<ll, ll>> factors;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.eb(0, i);
            while (n % i == 0) n /= i, factors.back().fi++;
        }
    }
    if (n > 1) factors.eb(1, n);
    return factors;
}

void GO() {
    ll n, num = 0;
    cin >> n;
    auto divisors = factorize(n);
    sort(divisors.rbegin() , divisors.rend()) ;
    vector<ll> ans;
    for (int i = 0; i < divisors.size(); ++i) num += divisors[i].se;
    if (num == 1) {
        cout << 1 << el << divisors[0].fi << el;
        return;
    }
    for (int i = 0; i < divisors.size(); ++i) {
        if (i == 0) {
            while (divisors[i].fi)ans.pb(divisors[i].se), divisors[i].fi--;
        }
        while (divisors[i].fi && divisors[i].se % ans.back() != 0) {
            if( (ans.size() == 1 || divisors[i].se % ans[ans.size()-2] == 0 ) && (ans.back() % divisors[i].se == 0)){
                ll temp = ans.back() ;
                ans.back() = divisors[i].se ;
                ans.pb(temp) ;
                divisors[i].fi -- ;
            }else ans.back() *= divisors[i].se , divisors[i].fi -- ;
        }
    }
    cout << ans.size() << el;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << el;


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
