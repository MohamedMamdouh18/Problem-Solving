#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
   IOS
   int t ;
   cin >> t;
   while(t--)
   {
       int n ;
       cin >> n ;
       vi a(n) ;
       rep(i , 0 , n)cin >> a[i] ;

       int positive = 0 , maxi = -1e9 ;
       ll total_sum = 0 ;
       rep(i , 0 , n)
       {
           if(i == 0)
           {
               if(a[i] > 0) positive = 1 ;
               else positive = 0 ;
           }
           if( (a[i] > 0 && positive) || (a[i] < 0 && !positive) ) maxi = max(maxi , a[i]) ;
           else if((a[i] < 0 && positive) || (a[i] > 0 && !positive))
           {
               total_sum += maxi ;
               maxi = a[i] ;
               positive = !positive ;
           }
       }
       total_sum += maxi ;
       cout << total_sum << endl ;
   }

}
