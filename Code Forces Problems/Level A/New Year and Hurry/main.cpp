#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
int main(){
   IOS
   int rem = 60 * 4 , num = 0 , t = 0;
   int n , k ;
   cin >> n >> k ;
   rem -= k ;
   while(rem - (t+5)>= 0)
   {
       num ++ ;
       t = num * 5 ;
       rem -= t ;
       if(num == n) break ;
   }
   cout << num ;
}
