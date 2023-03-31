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
   int n ;
   cin >>n ;
   vector<pair<int,int>> a(n) ;
   rep(i , 0 , n)
   {
       cin >> a[i].first ;
       a[i].second = i + 1 ;
   }
   srt(a) ;
   if(a[0].first == a[1].first) cout<<"Still Rozdil" ;
   else cout << a[0].second ;

}

