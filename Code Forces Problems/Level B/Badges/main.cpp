#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int b , g , n , decks = 0;
    cin >> b >> g >> n ;
    decks = n + 1 ;
    rep(i , 0 , n + 1)
    {
        if(i > b || n - i > g)
        {
            decks -- ;
        }
    }
    cout << decks ;
}
