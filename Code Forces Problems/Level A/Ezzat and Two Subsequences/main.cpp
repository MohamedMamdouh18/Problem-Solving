#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n ;
        double sum = 0 , maxi = LONG_LONG_MIN;
        cin >> n ;
        vector<double> num(n) ;
        for (int i = 0; i < n; ++i){
            cin >> num[i] ;
            sum += num[i] ;
            maxi = max(maxi , num[i]) ;
        }
        sum -= maxi ;
        sum /= (n-1) ;
        cout << fixed <<setprecision(8) << sum + maxi << el;
    }
}
