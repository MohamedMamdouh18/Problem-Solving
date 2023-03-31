#include <bits/stdc++.h>
using namespace std ;

#define mp make_pair
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int t ;
   cin >> t ;
   while(t--)
   {
       int n , time = 1;
       cin>> n ;
       queue<pair<int,int>> b ;
       vector<pair<int,int>> a(n) ;
       rep(i , 0 , n)
       {
           cin >> a[i].first ;
           cin >> a[i].second ;
       }

       rep(i , 0 , n) b.push(mp(a[i].first , a[i].second)) ;

       while(!b.empty())
       {
           if(time > b.front().second)
           {
               b.pop() ;
               cout << 0 << " " ;
           }
           else if(time >= b.front().first)
           {
               b.pop() ;
               cout << time << " " ;
               time ++ ;
           }
           else if(time < b.front().first)
           {
               while(time < b.front().first) time ++ ;
           }
       }
        cout << endl ;
   }
}
