#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    string s ;
    cin >> s ;
    int order = s.size() - 1  , sizee = s.size();
    while(true)
    {
        if(s[order] == '0')
        {
            order -- ;
        }
        else
        {
            break ;
        }
    }

    rep(i , 0 , order)
    {
        if(s[i] != s[order - i])
        {
            cout << "NO" ;
            return 0 ;
        }
    }
    cout << "YES" ;
}
