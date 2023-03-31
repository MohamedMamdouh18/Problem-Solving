#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define srt(a)     (sort(a.begin() , a.end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
 
int main(){
   IOS
   int n1 , n2 ;
   cin >> n1 >> n2 ;
   vi a(n1) ; vi b(n2) ;
   rep(i , 0 , n1) cin >>a[i] ;
   rep(i , 0 , n2) cin >>b[i] ;
 
   ll j = 0 , total = 0 , equali = 0;
   rep(i , 0 , n1)
   {
       if(a[i] == a[i-1] && i != 0)
       {
           total += equali ;
           continue ;
       }
       equali = 0 ;
       while(a[i] > b[j] && j < n2) j ++ ;
       while(a[i] == b[j] && j < n2)
       {
            j ++ ;
            equali ++ ;
       }
       total += equali ;
 
   }
   cout << total ;
}
