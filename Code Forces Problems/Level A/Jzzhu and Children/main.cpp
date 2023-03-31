#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int n, m, last, maxi = INT_MIN, l;
    cin >> n >> m;
    vector<int> x;
    for (int i = 0; i < n; ++i) {
        cin >> l;
        x.pb(ceil((float)l / m));
    }
 
    for (int i = x.size() - 1; i >= 0; --i)
        if (x[i] > maxi) {
            last = i + 1;
            maxi = x[i];
        }
 
    cout << last;
}
