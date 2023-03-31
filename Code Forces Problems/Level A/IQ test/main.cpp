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
   pair<int,int> even , odd ;
   cin >> n ;
   vi a(n) ;
   rep(i , 0 , n)
   {
       cin >> a[i] ;
       if(a[i] %2 == 0)
       {
           even.first ++ ;
           if(even.first == 1) even.second = i + 1 ;
       }
       else
       {
           odd.first ++ ;
           if(odd.first == 1) odd.second = i + 1 ;
       }
   }
   if(odd.first == 1) cout<<odd.second ;
   else cout <<even.second ;

}

