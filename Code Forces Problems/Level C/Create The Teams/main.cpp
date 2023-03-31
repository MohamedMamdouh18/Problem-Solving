#include <bits/stdc++.h>
 
using namespace std;
 
#define el "\n"
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        ll n , x , teams = 0;
        cin >> n >> x ;
        priority_queue<ll> programmers ;
        multiset<ll> crntTeam ;
        for (int i = 0; i < n; ++i) {
            int z ;
            cin >> z ;
            programmers.push(z) ;
        }
 
        while(!programmers.empty()){
            crntTeam.insert(programmers.top()) ;
            programmers.pop() ;
            if(*crntTeam.begin() * crntTeam.size() >= x) {
                teams ++ ;
                crntTeam.clear() ;
            }
        }
        cout << teams << el ;
    }
}
