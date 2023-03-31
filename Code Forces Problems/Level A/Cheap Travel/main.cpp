#include <bits/stdc++.h>

using namespace std;

int main() {
    int n ,m , a, b , ans = 0;
    cin >> n >> m >> a >> b ;
    if(b/m >= a) cout << a*n ;
    else{
        ans += n / m * b ;
        n %= m ;
        cout << ans + min(n * a,b) ;
    }
}
