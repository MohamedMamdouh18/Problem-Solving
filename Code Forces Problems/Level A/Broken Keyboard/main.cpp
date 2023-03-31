#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int t , m , n , x , y , total;
    string s ;
    cin >> t ;
    while(t--)
    {
        string s ;
        set<char> a ;
        int b[26] = {0} ;
        cin >> s ;
        rep(i , 0 , s.size())
        {
            b[s[i]-'a'] ++ ;
            if( (s[i] != s[i + 1] && i < s.size() - 1 && b[s[i]-'a'] % 2 == 1))
            {
                a.insert(s[i]) ;
            }
            if(i == s.size() - 1 && b[s[i]-'a'] % 2 == 1)
            {
                a.insert(s[i]) ;
            }
        }
        for(auto t : a)
        {
            cout << t ;
        }
        cout << endl ;
    }
}
