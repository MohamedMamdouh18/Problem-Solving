#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, x , flag = 1;
        cin >> n >> x;
        vector<int> original(n) , sorted(n) ;
        for (int i = 0; i < n; i++){
            cin >> original[i] ;
            sorted[i] = original[i] ;
        }
        if(is_sorted(original.begin() , original.end())){
            cout << "YES" << el ;
            continue;
        }
        sort(sorted.begin() , sorted.end()) ;
        for (int i = n-x; i < x; ++i) {
            if(original[i] != sorted[i]){
                flag = 0 ;
                break;
            }
        }
        if(!flag) cout << " NO" <<el ;
        else cout << "YES" << el ;

    }
}
