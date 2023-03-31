#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)
 
int main() {
    IOS
    int t ;
    cin >> t ;
    while(t --)
    {
        int x , y ;
        int ups = 0 , downs = 0 , rights = 0 , lefts  = 0 ;
        string s ;
        vector <char> a ;
        cin >> x >> y ;
        cin >> s ;
        rep(i , 0 , s.size())
        {
            a.pb(s[i]) ;
        }
 
        if(y > 0)
        {
            ups = y ;
        }
        if(y < 0)
        {
            downs = -y ;
        }
        if(x > 0)
        {
            rights = x ;
        }
        if(x < 0)
        {
            lefts = -x ;
        }
 
        if(cnt(a,'D') < downs && downs != 0)
        {
            cout << "no" << endl ;
            continue ;
        }
        if(cnt(a,'U') < ups && ups != 0)
        {
            cout << "no" << endl ;
            continue ;
        }
        if(cnt(a,'R') < rights && rights != 0)
        {
            cout << "no" << endl ;
            continue ;
        }
        if(cnt(a,'L') < lefts && lefts != 0)
        {
            cout << "no" << endl ;
            continue ;
        }
        cout << "yes" << endl;
    }
}
