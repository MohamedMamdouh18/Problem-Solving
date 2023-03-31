#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t ;
    cin >> t ;
    while (t --){
        int n , maxPower;
        cin >> n ;
        for (int i = 0; i < 32; ++i) {
            if((1 << i) > n) break ;
            if(n & (1 << i)) maxPower = 1 << i ;
        }

        cout << maxPower - 1<< "\n" ;
    }
}
