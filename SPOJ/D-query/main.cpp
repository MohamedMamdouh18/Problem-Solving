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
const ll mod = 1e9 + 7, N = 1e6+1;
int cnt[N];
ll n, t,k , block, sum = 0;
vector<pair<pair<ll, ll>, ll>> queries;
vector<ll> num, ans;

void add(int pos) {
    if(cnt[num[pos]] == 0) sum ++ ;
    cnt[num[pos]] ++;
}

void remove(int pos) {
    if(cnt[num[pos]] == 1) sum -- ;
    cnt[num[pos]] --;
}

void solveMO() {
    int currentL = 0, currentR = 0;
    sum = 1 , cnt[num[0]] ++;
    for (auto query: queries) {
        while (currentL < query.fi.fi) {
            remove(currentL);
            currentL++;
        }
        while (currentL > query.fi.fi) {
            currentL--;
            add(currentL);
        }
        while (currentR < query.fi.se) {
            currentR++;
            add(currentR);
        }
        while (currentR > query.fi.se) {
            remove(currentR);
            currentR--;
        }
        ans[query.se] = sum;
    }

}

bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    ll pos1 = (a.fi.fi / block), pos2 = (b.fi.fi / block);
    if (pos1 ^ pos2) return pos1 < pos2;
    return a.fi.se < b.fi.se;
}

void GREEN() {
    cin >> n ;
    block = sqrt(n);
    num.resize(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    cin >> t ;
    queries.resize(t), ans.resize(t);

    for (int i = 0; i < t; ++i) {
        cin >> queries[i].fi.fi >> queries[i].fi.se;
        queries[i].fi.fi-- , queries[i].fi.se --;
        queries[i].se = i;
    }
    sort(all(queries), cmp);
    solveMO();
    for (int i = 0; i < t; ++i) {
        cout << ans[i] << el;
    }
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
