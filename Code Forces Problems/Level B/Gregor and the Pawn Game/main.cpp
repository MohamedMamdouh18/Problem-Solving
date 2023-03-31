#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);\
 
int main(){
   IOS
   int t ;
   cin >> t ;
   while(t --)
   {
       int n ;
       cin >>n ;
       string s1 , s2 ;
       cin >> s1 >> s2 ;
       int cont = 0 ;
       rep(i , 0 , n)
       {
           if(i == 0 && s2[i] == '1')
           {
               if(s1[i] == '0' )
               {
                   s1[i] = '2' ; cont ++ ;
               }
               else if(s1[i+1] == '1')
               {
                   s1[i+1] = '2' ; cont ++ ;
               }
           }
           else if(i == n-1 && s2[i] == '1')
           {
               if(s1[i] == '0' )
               {
                   s1[i] = '2' ; cont ++ ;
               }
               else if(s1[i-1] == '1')
               {
                   s1[i-1] = '2' ; cont ++ ;
               }
           }
           else if(s2[i] == '1')
           {
               if(s1[i] == '0' )
               {
                   s1[i] = '2' ; cont ++ ;
               }
               else if(s1[i-1] == '1')
               {
                   s1[i-1] = '2' ; cont ++ ;
               }
               else if(s1[i+1] == '1')
               {
                   s1[i+1] = '2' ; cont ++ ;
               }
           }
       }
       cout << cont << endl ;
   }
}
