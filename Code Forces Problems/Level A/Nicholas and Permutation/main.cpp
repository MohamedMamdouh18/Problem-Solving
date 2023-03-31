#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n , least ,biggest;
    cin >> n ;
    vector<int> a(n) ;
    rep(i , 0 , n)
    {
        cin >>a[i] ;
        if(a[i] == 1) least = i + 1 ;
        if(a[i] == n) biggest = i + 1 ;
    }

    int num1 = max(abs(least - n) ,abs(least - 1)) ;
    int num2 = max(abs(biggest - n) ,abs(biggest - 1)) ;
    cout << max(num1 , num2) ;
}
