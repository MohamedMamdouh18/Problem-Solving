#include <bits/stdc++.h>
using namespace std ;

#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int n ;
   cin >> n ;
   int t = n , l = 0 ,flag = 0;

   rep(i , 0 , n)
   {
       rep(j , 0 , n)
       {
           if(!flag)
           {
               cout << 1 + l << " " ;
               flag = !flag ;
           }
           else
           {
               cout << pow(n,2)-l << " " ;
               flag = !flag ;
               l ++ ;
           }

       }
       cout << endl ;
   }
}
