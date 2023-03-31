#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define isfind(a,s)  a.find(s) != a.npos

string s1 , s2 ;
vi a ;

bool good(int x)
{
    string s = "" , z = s1 ;
    rep(i , 0 , x) z[a[i]-1] = '0' ;
    rep(i , 0 , z.size()) if(z[i] != '0') s.pb(z[i]) ;

    int l = 0 , same = 0 ; //for s
    rep(r , 0 , s2.size()) // r for s2
    {
        while(s[l] != s2[r] && l < s.size()) l ++ ;
        if(s[l] == s2[r] && l < s.size())
        {
            same ++ ; l ++ ;
        }
    }
    return same == s2.size() ;
}

int main(){
   IOS
   cin >> s1 >> s2 ;
   int x ;
   rep(i , 0 , s1.size())
   {
       cin >> x;
       a.pb(x) ;
   }

   int l = 0 , r = s1.size();
   while(r > l + 1)
   {
       int mid = (l+r) / 2 ;
       if(good(mid)) l = mid ;
       else r = mid ;
   }

   cout << l ;
}
