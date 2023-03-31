#include <bits/stdc++.h>
using namespace std ;
 
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main(){
   IOS
   int n;
   cin >> n ;
   vector<int> a(n) ;
   vector<int> b(n-1) ;
   vector<int> c(n-2) ;
   rep(i , 0 , n)
   {
       cin >> a[i] ;
   }
   srt(a) ;
   rep(i , 0 , n-1)
   {
       cin >> b[i] ;
   }
   srt(b) ;
   rep(i , 0 , n-2)
   {
       cin >> c[i] ;
   }
   srt(c) ;
   int flag = 0 ;
   rep(i , 0 ,n-1)
   {
       if(a[i] !=b[i])
       {
           cout <<a[i] << endl ;
           flag = 1 ;
           break ;
       }
   }
   if(!flag) cout << a[n-1] << endl ;
   flag = 0 ;
 
   rep(i , 0 ,n-2)
   {
       if(c[i] !=b[i])
       {
           cout <<b[i] << endl ;
           flag = 1 ;
           break ;
       }
   }
   if(!flag) cout << b[n-2] << endl ;
}
