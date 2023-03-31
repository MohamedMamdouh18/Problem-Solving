#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define srt(a)     (sort(a.begin() , a.end()))
#define minv(a)      (*min_element((a).begin(), (a).end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
int main(){
   IOS
   int t;
   cin >> t ;
   while(t--)
   {
       int n , odd = 0 , even = 0;
       cin >> n ;
       int a[n] ;
       rep(i,0,n) cin>>a[i] ;
       rep(i , 0 , n)
       {
           if(a[i]%2 == 0) even ++ ;
           else odd ++ ;
       }
       if(n % 2 == 0)
       {
           if(even == 0 || odd == 0) cout << "NO"<< endl ;
           else cout << "YES"<< endl ;
       }
       else
       {
           if(odd > 0) cout << "YES"<< endl ;
           else cout << "NO"<< endl ;
       }
   }
}
