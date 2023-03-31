#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main(){
   IOS
   ll n , m ;
   cin >> n >> m ;
   vector<ll> dormitory(n) ;
   vector<ll> letters(m) ;
   rep(i , 0 , n) cin>>dormitory[i] ;
   rep(i , 0 , m) cin>>letters[i] ;
 
   int l = 0 ;
   ll total_passed = 0 , passed=0;
   rep(r , 0 , m)
   {
       letters[r] -= total_passed ;
       if(letters[r] <= dormitory[l])
       {
           total_passed += letters[r] ;
           passed += letters[r] ;
           dormitory[l] -= letters[r] ;
           cout << l+1 << " " << passed << endl;
       }
       else
       {
           while(letters[r] > dormitory[l])
           {
               letters[r] -= dormitory[l] ;
               total_passed += dormitory[l] ;
               l ++ ;
               passed = 0 ;
           }
           total_passed += letters[r] ;
           passed += letters[r] ;
           dormitory[l] -= letters[r] ;
           cout << l+1 << " " << passed << endl;
       }
   }
 
}
