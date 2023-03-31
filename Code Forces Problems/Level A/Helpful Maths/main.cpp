#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s ; vector<char> a ;
    cin >> s ;
    for(int i = 0 ; i < s.size() ; i += 2)
    {
        a.push_back(s[i] ) ;
    }
    sort(a.begin() , a.end()) ;
    for(int i = 0 ; i < s.size() ; i += 2)
    {
        s[i] = a[i / 2]  ;
    }

    cout << s ;
}
