#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
 
int main(){
   IOS
   int n ;
   cin >> n ;
   vi c(n-1) ;
   rep(i , 0 , n-1) cin >>c[i] ;
   int a, b ;
   cin >> a >> b ;
   int time = 0;
   rep(i , a , b)
   {
       time += c[i-1] ;
   }
   cout << time ;
}
