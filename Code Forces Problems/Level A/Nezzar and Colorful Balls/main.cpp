#include <bits/stdc++.h>
using namespace std ;

#define vi vector<int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int t ;
    cin >> t ;
    while(t--)
    {
        vi freq(101) ;
        int n , num;
        cin >> n ;
        rep(i , 0 , n)
        {
            cin >> num ;
            freq[num] ++ ;
        }
        cout << maxv(freq) << endl ;
    }
}
