#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, x, maxi = INT_MIN;
    cin >> n;
    set<pair<int, int>> a, b;
    vector<int> shift(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.insert({x, i + 1});
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        b.insert({x, i + 1});
    }
    auto it = a.begin();
    for (auto item: b) {
        if (item.se > it->se) {
            shift[n - item.se + it->se]++;
        } else {
            shift[it->se - item.se]++;
        }
        it++;
    }
    maxi = *max_element(shift.begin() , shift.end()) ;
    cout << maxi ;
}
