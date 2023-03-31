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
ll mod = 1e9 + 7;
 
ll fact[1001], invfact[1001];
 
ll mul(ll x, ll y, ll m) {
    return ((x % m) * (y % m)) % m;
}
 
ll fp(ll base, ll power){
    if(power == 0)
        return 1;
    ll res = fp(base, power >> 1);
    res = mul(res, res, mod);
    if(power & 1) res = mul(res, base, mod);
    return res;
}
void init() {
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i < 1001; i++) {
        fact[i] = mul(fact[i - 1], i, mod);
        invfact[i] = fp(fact[i], mod - 2);
    }
}
ll ncr(int n, int r) {
    ll m1 = mul(fact[n], invfact[n - r], mod);
    m1 = mul(m1, invfact[r], mod);
    return m1;
}
 
void GREEN() {
    int n, k, same = 0, last = -1, lastPos;
    cin >> n >> k;
    int choose = k;
    vector<int> num(n);
    map<int, int> occur;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        occur[num[i]]++;
    }
    sort(num.rbegin(), num.rend());
    for (int i = 0; i < n; ++i) {
        k--;
        if (num[i] == last) same++;
        else {
            same = 1;
            last = num[i];
            lastPos = i;
        }
        if (k == 0) {
            i++;
            while (i < n && num[i] == last) i++, same++;
            break;
        }
    }
    choose -= lastPos;
    cout << ncr(same, choose) << el;
}
 
int main() {
    IOS
    PREC
    init();
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
