#include <bits/stdc++.h>
using namespace std ;


#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
    IOS
   int k , l , m , n , d , total = 0;
   cin >> k >> l >> m >> n >> d ;

   rep(i , 1 , d + 1) if((i%k==0) ||(i%l==0) ||(i%m==0) ||(i%n==0)) total ++ ;


    cout << total ;
}
