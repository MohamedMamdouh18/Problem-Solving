#include <bits/stdc++.h>
using namespace std ;

#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
   IOS
   int n , m , right = 1,last_row;
   cin >> n >> m ;
   char arr[n][m] ;
   rep(i , 0 , n)
   {
       rep(j , 0 , m)
       {
           if(i%2 == 0)arr[i][j] = '#' ;
           else if(i % 2 == 1 && ((j == 0 && !right)  || (j == m -1 && right)) && i != last_row)
           {
               arr[i][j] = '#' ;
               right = !right ;
               last_row = i ;
           }
           else arr[i][j] = '.' ;
       }
   }

   rep(i , 0 , n)
   {
       rep(j , 0 , m) cout << arr[i][j];
       cout << endl ;
   }

}

