#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

double c ;
bool good(double x)
{
  return pow(x,2) + sqrt(x) <= c ;
}

int main(){
   IOS
   cin >> c ;
   double l = 0 , r = 1e10 ;

   rep(i , 0 , 100)
   {
       double mid = (l+r) / 2 ;
       if(good(mid)) l = mid ;
       else r = mid ;
   }

   cout << setprecision(20) <<l ;
}
