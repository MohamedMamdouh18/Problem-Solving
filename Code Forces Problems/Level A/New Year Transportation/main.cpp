#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
vector<vector<int>> adj_list(100000) ;
int t , n;
 
bool dfs(int node)
{
 
    if(node > t-1)return false ;
    if(node == t-1) return true ;
 
 
    int child = adj_list[node][0] ;
    dfs(child) ;
 
}
 
int main(){
   IOS
   int x , last = 0;
   cin >> n >> t ;
 
   rep(i , 0 , n-1)
   {
       cin  >> x ;
       if(i == last)
       {
           adj_list[last].pb(last+x);
           last += x ;
       }
   }
 
   cout << (dfs(0) ? "YES" : "NO") ;
}
