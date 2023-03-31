
#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    string s ; set<int> m;
    getline(cin , s) ;
    for(int i = 0 ; i < s.size() ; i ++)
    {
        if(isalpha(s[i]))
        {
            m.insert(s[i]) ;
        }
    }
 
    cout << m.size() ;
}
