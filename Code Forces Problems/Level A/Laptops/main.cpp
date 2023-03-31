#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define srt(a)     (sort(a.begin() , a.end()))

int main(){
   IOS
   int n ;
   cin >> n ;
   vector<pair<int,int>> laptop(n) ;
   rep(i , 0 , n) cin >> laptop[i].first >> laptop[i].second ;
   srt(laptop) ;

   rep(i , 0 , n-1)
   {
       if(laptop[i].second > laptop[i+1].second)
       {
           cout <<"Happy Alex" ;
           return 0 ;
       }
   }

   cout << "Poor Alex" ;
}
