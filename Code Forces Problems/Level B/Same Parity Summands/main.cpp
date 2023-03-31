#include <bits/stdc++.h>
using namespace std ;

#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int t ;
   cin >> t ;
   while(t--)
   {
       int n , k ;
       cin >>n >> k ;
       if(k == 1)
       {
           cout << "YES" << endl << n << endl;
           continue ;
       }

       int rest = n - k + 1 ;
       if(rest % 2 && rest > 0)
       {
           cout << "YES" << endl ;
           rep(i , 0 , k - 1) cout << 1 << " " ;
           cout << rest << endl ;
       }
       else if((rest - k + 1) % 2 == 0  && rest - k + 1 > 0)
       {
           cout << "YES" << endl ;
           rep(i , 0 , k - 1) cout << 2 << " " ;
           cout << rest - k + 1 << endl ;
       }
       else cout << "NO" << endl ;
   }
}
