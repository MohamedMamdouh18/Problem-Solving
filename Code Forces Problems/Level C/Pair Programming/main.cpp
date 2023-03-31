#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main(){
   IOS
   int t ;
   cin >> t;
   while(t--)
   {
       int k , n , m , flag = 0;
       cin >> k >> n >> m ;
       vi a(n) ; vi b(m) ;
       rep(i, 0 , n) cin >>a[i] ;
       rep(i, 0 , m) cin >>b[i] ;
       vi c ;
 
       int l = 0 , r = 0 ;
       while(l != m || r != n)
       {
           if(((b[l] > k && a[r] > k) ||(a[r] > k && l >= m) || (b[l] > k && r >= n)))
           {
               flag = 1 ; break ;
           }
           while(a[r] <= k && r < n)
           {
               c.pb(a[r]) ;
               if(a[r] == 0) k ++ ;
               r ++ ;
           }
           while(b[l] <=k && l < m)
           {
               c.pb(b[l]) ;
               if(b[l] == 0) k ++ ;
               l ++ ;
           }
 
 
       }
       if(flag)
       {
           cout << -1 << endl ;
       }
       else
       {
           rep(i , 0 ,c.size()) cout << c[i] << " " ;
           cout << endl ;
       }
   }
}
