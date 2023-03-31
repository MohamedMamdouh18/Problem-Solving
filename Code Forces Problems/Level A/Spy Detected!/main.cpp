#include <bits/stdc++.h>
using namespace std ;

#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
   IOS
   int t ;
   cin >> t ;
   while(t --)
   {
       int n ;
       cin >> n ;
       vi a(n) ;
       rep(i , 0 , n) cin >> a[i] ;
       rep(i , 0 , n)
       {
           if(i != 0 && i != 1 && a[i] != a[i-1])
           {
               cout << i + 1 << endl ;
               break ;
           }
           else if(i == 1 && a[i] == a[i+1] && a[i] != a[i-1])
           {
               cout << 1 << endl ;
               break ;
           }
           else if(i == 1 && a[i] != a[i+1] && a[i] != a[i-1])
           {
               cout << 2 << endl ;
               break ;
           }
       }
   }

}

