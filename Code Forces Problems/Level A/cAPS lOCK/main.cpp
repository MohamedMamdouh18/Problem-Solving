
#include <bits/stdc++.h>
using namespace std ;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    string s ;
    cin >> s ;
    if(s.size() == 1)
    {

        if(islower(s[0]))
        {
            s[0] = toupper(s[0]) ;
        }
        else
        {
            s[0] = tolower(s[0]) ;
        }
        cout << s ;
        return 0 ;
    }
    if(islower(s[0]))
    {
        rep(i , 1 , s.size())
        {
            if(islower(s[i]))
            {
                cout << s ;
                return 0 ;
            }
        }
        s[0] = toupper(s[0]) ;
        rep(i , 1 , s.size())
        {
            s[i] = tolower(s[i]) ;
        }
    }
    else
    {
        rep(i , 0 , s.size())
        {
            if(islower(s[i]))
            {
                cout << s ;
                return 0 ;
            }
        }
        rep(i , 0 , s.size())
        {
            s[i] = tolower(s[i]) ;
        }
    }
    cout << s ;
}
