
#include <bits/stdc++.h>
using namespace std ;

#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)
 
int main() {
    IOS
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    vector<int> a(26) ;
    rep(i , 0 , s.size())
    {
        s[i] = tolower(s[i]) ;
        a[s[i] -'a'] ++ ;
    }
    if(cnt(a , 0) > 0)
    {
        cout << "NO" ;
    }
    else
    {
        cout <<"YES" ;
    }
}
