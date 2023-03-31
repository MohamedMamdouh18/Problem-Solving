#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define srt(a)     (sort(a.begin() , a.end())
 
int main(){
   IOS
   int t;
   cin >> t ;
   while(t--)
   {
       int n , num = 0;
       cin >> n ;
       string s1 , s2;
       cin >> s1 ;
       s2 = s1 ;
       srt(s2) ;
       rep(i , 0 , n)
       {
           if(s1[i] != s2[i]) num ++ ;
       }
       cout <<num << endl ;
   }
}
