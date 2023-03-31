#include <bits/stdc++.h>
#include <math.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
int main(){
   IOS
   int n , l ;
   cin >> n >> l;
   vector <double> a(n) ;
   rep(i , 0 , n) cin >> a[i] ;
   srt(a) ;
   rep(i , 0 , a.size())
   {
       if(i != a.size()-1)a.insert(a.begin()+i+1 , (a[i]+a[i+1]) / 2) ;
       i ++ ;
   }
   double maxi = -1 ;
   if(a[0] != 0) a.insert(a.begin() , 0) ;
   if(a[a.size()-1] != l) a.push_back(l) ;
 
   rep(i , 0 ,a.size()-1)
   {
       if(a[i+1] - a[i] > maxi) maxi = a[i+1] - a[i] ;
   }
 
   cout << setprecision(20) << maxi ;
}
