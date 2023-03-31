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
    int t;
    cin >> t;
    while (t--) {
        ll n , w , sum = 1 , x;
        cin >> n >> w ;
        multiset<ll> boxes ;
        for (int i = 0; i < n; ++i){
            cin >> x ;
            boxes.insert(x) ;
        }
 
        ll crnt = w ;
        while(!boxes.empty()){
            auto it = --boxes.upper_bound(crnt) ;
            if(*it > crnt){
                sum ++ ;
                crnt = w ;
            }else{
                crnt -= *it ;
                boxes.erase(it) ;
            }
        }
        cout << sum << el ;
    }
}
