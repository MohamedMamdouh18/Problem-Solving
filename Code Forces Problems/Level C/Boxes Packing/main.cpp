#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e5;

void GREEN() {
    int n ;
    cin >> n  ;
    int ans = n ;
    vector<int> box(n) ;
    vector<bool> visited(n) ;
    for (int i = 0; i < n; ++i) cin >> box[i] ;
    sort(all(box));
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            if(box[i] < box[j] && !visited[j]) {
                ans -- , visited[j] = true ;
                break;
            }
        }

    cout << ans ;
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
