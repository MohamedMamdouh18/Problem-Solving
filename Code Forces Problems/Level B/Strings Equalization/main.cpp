#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n ;
    cin >> n ;
    while(n --)
    {
        int found = 0 ;
        string s ; string t ;
        cin >> s >> t ;
        set <char> s1 ; set <char> t1 ;
        rep(i , 0 , s.size())
        {
            s1.insert(s[i]) ;
            t1.insert(t[i]) ;
        }

        for(auto elem : s1)
        {
            if(t1.count(elem))
            {
                cout<< "yes" << endl ;
                found = 1;
                break ;
            }
        }
        if(!found)
        {
           cout<< "no" << endl ;
        }
        found = 0 ;

    }

}
