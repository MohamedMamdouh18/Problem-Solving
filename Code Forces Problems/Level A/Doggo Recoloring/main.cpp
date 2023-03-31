
#include <bits/stdc++.h>
using namespace std ;

#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    int n ;
    cin >> n ;
    vector <int> a(26) ;
    string s ;
    cin >> s ;
    rep(i , 0 , n)
    {
        a[s[i] - 'a'] ++ ;
    }
    if(maxv(a) == s.size() || maxv(a) > 1)
    {
        cout << "YES" ;
    }
    else
    {
        cout << "NO" ;
    }
}
