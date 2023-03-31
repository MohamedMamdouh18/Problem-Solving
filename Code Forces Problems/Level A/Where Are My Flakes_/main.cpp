#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
   IOS
   int n , m ;
   cin >> n >> m ;
   int l = 1 , r = n ;
   rep(i , 0 , m)
   {
       string s1 , s2 , s3 , s4 ;
       cin >> s1 >> s2 >> s3 >> s4;
       int num ;
       cin >> num ;
       if(s3 == "right") l = max(l ,num + 1);
       else r =min(r , num - 1);
   }

   if(r - l < 0) cout << -1 ;
   else cout << r - l + 1;
}
