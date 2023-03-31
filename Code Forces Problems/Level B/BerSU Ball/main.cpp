#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define srt(a)     (sort(a.begin() , a.end()))

int main(){
   IOS
   int n1 , n2 ;
   cin>>n1 ;
   vector <int> boy(n1) ;
   rep(i,0,n1) cin>>boy[i] ;
   cin>>n2 ;
   vector <int> girl(n2) ;
   rep(i,0,n2) cin>>girl[i] ;

   srt(girl) ; srt(boy) ;
   int b = 0 , g = 0 , pairs = 0 , last_valid = 0;
   while(b < n1)
   {
       if(abs(boy[b] - girl[g]) == 1 || boy[b] - girl[g] == 0)
       {
           pairs ++ ;
           b ++ ; g ++ ;
           last_valid = g ;
           if(g == n2) break ; 
       }
       else
       {
           g ++ ;
       }
       if(g == n2)
       {
           g = last_valid ;
           b ++ ;
       }
   }
   cout << pairs ;
}
