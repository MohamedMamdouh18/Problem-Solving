#include <bits/stdc++.h>
 
using namespace std;
 
#define el "\n"
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t ;
    cin >> t ;
    while(t --){
        vector<ll> b(7) ;
        for(auto &item : b) cin >> item ;
 
        cout << b[0] << " " << b[1] << " ";
        cout << ((b[2] == b[1] + b[0]) ? b[3] : b[2]) << el ;
    }
}
