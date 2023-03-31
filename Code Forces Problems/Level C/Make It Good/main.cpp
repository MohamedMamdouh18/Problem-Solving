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
const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;
vector<int> num;

bool good(int prefix) {
    int maxi = -1;
    int l = prefix, r = num.size() - 1;
    for (int i = prefix; i < num.size(); ++i) {
        int cur;
        if (num[l] < num[r]) {
            cur = num[l];
            l++;
        } else {
            cur = num[r];
            r--;
        }
        if (cur < maxi) return false;
        else maxi = cur;
    }
    return true;
}

void GREEN() {
    int n;
    cin >> n;
    num.clear();
    num.resize(n);
    for (int i = 0; i < n; ++i) cin >> num[i];
    int l = 0, r = n - 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (good(mid)) r = mid;
        else l = mid;
    }
    if (r == 1 && good(r - 1)) r--;
    cout << r << el;
}

int main() {
    PREC
    IOS
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
