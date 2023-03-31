#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<vector<int>> adj_list(200001) ;
set<int> path ;
vector<int> question ;
int vis[200001] = {0} ;
int n , flag = 1;

void bfs(int node)
{
   int siz1 = 0 , siz2 = 0 , child , pointer = 1;
   queue<int> q ;
   q.push(node) ;
   path.insert(node) ;
   for(; !q.empty() ; siz1 = q.size())
   {
       while(siz1 --)
       {
           int cur = q.front() ; q.pop() ;
           vis[cur] = 1;
           rep(i , 0 , adj_list[cur].size())
           {
               child = adj_list[cur][i] ;
               if(!vis[child])
               {
                   siz2 ++ ;
                   path.insert(child) ;
                }
           }
           rep(i , pointer , pointer+siz2)
           {
               if(!path.count(question[i]))
               {
                   flag = 0 ;
                   return ;
               }
           }
           rep(i , pointer , siz2+pointer) q.push(question[i]) ;
           pointer += siz2 ;
           siz2 = 0 ;
           path.clear() ;
       }
   }
}

int main(){
   IOS
   int x , y ;
   cin >> n ;
   rep(i , 0 , n-1)
   {
       cin >> x >> y ;
       adj_list[x].pb(y) ;
       adj_list[y].pb(x) ;
   }
   rep(i , 0 , n)
   {
       cin >> x;
       question.pb(x) ;

   }
   if(question[0] != 1)
   {
       cout << "No" ;
       return 0 ;
   }

   bfs(1) ;
   if(flag) cout << "Yes" ;
   else cout << "No" ;
}
