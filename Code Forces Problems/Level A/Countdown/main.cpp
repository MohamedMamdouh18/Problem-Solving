#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t ;
    cin >> t ;
    while(t--)
    {
        string s ;
        int n , ans = 0;
        cin >> n ;
        cin >> s ;
        for (int i = 0; i < n; ++i) {
            ans += s[i] - '0' ;
            if(i != n-1 && s[i] != '0') ans ++ ;
        }
        cout << ans << endl ;
    }
}
