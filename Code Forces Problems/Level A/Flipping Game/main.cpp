#include <bits/stdc++.h>
using namespace std ;

#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
   IOS
   int n ;
   cin >> n ;
   vector<int> a(n) ;
   rep(i , 0 , n) cin >>a[i] ;
   int ones1 = cnt(a , 1) ;
   if(ones1 == n)
   {
       cout << ones1 - 1 ;
       return 0 ;
   }
   vector <int> max_ones ;
   rep(i , 0 , n)
   {
       if (a[i] == 0)
       {
           int ones2 = 0 ;
           rep(j , i , n)
           {
               if(a[j] == 0) ones2 ++ ;
               else ones2 -- ;
               if (ones2 >= 0)
               {
                   max_ones.pb(ones2) ;
               }
           }
       }
   }
   if(max_ones.empty())cout<<ones1 ;
   else cout<<ones1 + maxv(max_ones) ;
}
