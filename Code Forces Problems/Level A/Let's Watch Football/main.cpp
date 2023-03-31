#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int a , b , c;
 
bool good(int x)
{
    return (c*a - b*x)  <= (b * c)  ;
}
 
int main(){
   IOS
   cin >> a >> b >> c ;
 
   int l = 0 ;
   int r = 1 ;
   while(!good(r)) r*=2 ;
 
   while(r > l+1)
   {
       int mid = (r+l) / 2 ;
       if(good(mid)) r = mid ;
       else l = mid ;
   }
   cout << r ;
}
