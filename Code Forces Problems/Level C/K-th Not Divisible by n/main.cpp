#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll n ,  k;
bool good(ll x)
{
    ll ans = x / n + k ;
    return ans <= x ;
}
 
int main() {
    IOS
    int t ;
    cin >> t ;
    while(t --)
    {
        cin >> n >> k;
        ll l = 0 , r = 1 ;
        while(!good(r)) r *= 2 ;
        while(r > l+1)
        {
            ll mid = (l+r) / 2 ;
            if(good(mid)) r = mid ;
            else l = mid ;
        }
        cout << r << endl ;
    }
}
