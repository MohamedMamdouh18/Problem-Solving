#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
int main() {
    IOS
    int n , x = 0 ;
    string s ;
    cin >> n ;
    while(n--)
    {
        cin >> s ;
        if(s[1] == '+') x ++ ;
        else x -- ;
    }
    cout << x ;
}
