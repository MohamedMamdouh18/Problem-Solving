#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define srt(a)     (sort(a.begin() , a.end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
 
int freq_a[100000] ;
 
int main(){
   IOS
   ll n , k ;
   cin >> n >> k ;
   vi a(n) ;
   rep(i , 0 , n) cin >>a[i] ;
   ll l = 0 , num = 0 , uniq = 0;
   rep(r , 0 , n)
   {
       freq_a[a[r]] ++ ;
       if(freq_a[a[r]] == 1) uniq ++ ;
       while(uniq > k)
       {
           freq_a[a[l]] -- ;
           if(freq_a[a[l]] == 0)uniq -- ;
           l ++ ;
       }
       if(uniq <= k) num += r-l+1 ;
   }
   cout << num ;
 
}
