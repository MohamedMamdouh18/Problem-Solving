#include <bits/stdc++.h>
using namespace std ;

#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int n ; string s ;
   cin >> n ;
   cin >> s ;
   int num = 0 , change;
   rep(i , 0 , n)
   {
       if(s[i] == 'X') num++ ;
   }
   change = abs(num - (n / 2));
   rep(i , 0 , n)
   {
       if(s[i] == 'X' && num > n / 2 && change != 0)
       {
           s[i] = tolower(s[i]) ;
           change -- ;
       }
       else if(s[i] == 'x' && num < n/2 && change != 0)
       {
           s[i] = toupper(s[i]) ;
           change -- ;
       }
   }
   cout << abs(num - (n / 2)) << endl << s ;
}
