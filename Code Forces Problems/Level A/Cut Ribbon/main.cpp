#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, a, b, c, ans = 0;
    cin >> n >> a >> b >> c;

    for (int i = 0; i <= 4000; ++i) {
        for (int j = 0; j <= 4000; ++j) {
            int k = (n - a*i - b*j)/c ;
            if(k < 0) break ;
            int f1 = a * i ;
            int f2 = b * j ;
            int f3 = c * k ;
            if(n == f1+f2+f3){
                ans = max(ans , i + j + k) ;
            }
        }
    }
    cout << ans ;
}
