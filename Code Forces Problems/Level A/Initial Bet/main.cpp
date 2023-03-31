#include <bits/stdc++.h>
using namespace std ;

#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
   IOS
   int sum = 0;
   int l ;
   rep(i , 0 , 5)
   {
       cin >> l ;
       sum += l ;
   }
   if(sum % 5 == 0 && sum != 0) cout<< sum / 5 ;
   else cout << - 1;

}

