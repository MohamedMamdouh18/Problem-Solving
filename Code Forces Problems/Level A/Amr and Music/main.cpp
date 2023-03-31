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
   int n , k ;
   cin >>n >> k ;
   vector<pair<int,int>> a(n) ;
   rep(i , 0 , n)
   {
       cin >> a[i].first ;
       a[i].second = i + 1 ;
   }
   srt(a) ;
   int num = 0 ; vi b ;
   rep(i , 0 , n)
   {
       if(k >= a[i].first)
       {
           num ++ ;
           k -= a[i].first ;
           b.pb(a[i].second) ;
       }
       else break ;
   }
   cout << num << endl;
   rep(i , 0 , num)
   {
       cout<<b[i] << " " ;
   }

}

