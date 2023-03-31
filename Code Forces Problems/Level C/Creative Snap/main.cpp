#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll a, b;
vector<int> avengers;

ll burn(ll start, ll end) {
    ll length = end - start + 1;
    ll num = upper_bound(all(avengers), end) - lower_bound(all(avengers), start);
    if (num == 0) return a;
    if (start == end) return b * num;
    
    ll mid = (start + end) / 2;
    ll cost2 = burn(start, mid);
    cost2 += burn(mid + 1, end);
    return min(cost2, length * num * b);
}

int main() {
    IOS
    ll n, k;
    cin >> n >> k >> a >> b;
    n = pow(2, n);

    avengers.resize(k);
    for (int i = 0; i < k; ++i) cin >> avengers[i];

    sort(all(avengers));
    cout << burn(1, n);

}
