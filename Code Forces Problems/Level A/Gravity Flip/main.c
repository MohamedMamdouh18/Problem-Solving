#include <bits/stdc++.h>
using namespace std ;


#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int n ;
   cin >> n ;
   vector<int> a(n) ;
   rep(i , 0 , n) cin >> a[i] ;
   srt(a) ;
   rep(i , 0 , n) cout <<a[i] << " " ;
}
