#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define ll long long
#define all(a) a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n ,x;
        cin >> n ;
        vector<ll> num(n) ,prefix(n);
        for (int i = 0; i < n; ++i) cin >> num[i] ;
        sort(all(num)) ;

        for (int i = 0; i < n - 1; ++i) prefix[i+1] = num[i] + prefix[i] ;

        for (int i = 0; i < n - 1; ++i) num[i+1] += -prefix[i+1] + prefix[i] ;
        cout << *max_element(all(num)) << el ;
    }
}
