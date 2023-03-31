#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t ;
    cin >> t ;
    while(t --)
    {
        ll n , ans = 0;
        cin >> n ;
        while(n >= 2)
        {
            int i = 1 ;
            while((n - ((i*2) + i - 1)) >= 0)
            {
                n -= (i*2) + i - 1 ;
                i ++ ;
            }
            ans ++ ;
        }
        cout << ans << endl ;
    }
}
