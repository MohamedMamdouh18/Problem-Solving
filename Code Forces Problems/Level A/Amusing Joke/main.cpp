
#include <bits/stdc++.h>
using namespace std ;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    string s1 ; string s2 ; string s3 ;
    int a12[26] = {0} ; int a3[26] ={0} ;
    cin >> s1 >> s2 >> s3 ;
    rep(i , 0 , s1.size())
    {
        a12[s1[i]-'A'] ++ ;
    }
    rep(i , 0 , s2.size())
    {
        a12[s2[i]-'A'] ++ ;
    }
    rep(i , 0 , s3.size())
    {
        a3[s3[i]-'A'] ++ ;
    }
    rep(i , 0 , 26)
    {
        if(a12[i] != a3[i])
        {
            cout <<"NO" ;
            return 0 ;
        }
    }
    cout << "YES" ;
}
