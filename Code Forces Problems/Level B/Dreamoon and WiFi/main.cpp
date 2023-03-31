#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
string s1 , s2 ;
vector <int> poss ;
int pos = 0 ;

void bfs()
{
   queue<int> q ;
   int siz = 0 , depth = 0;
   if(s2[depth] == '+') q.push(1) ;
   else if(s2[depth] == '-') q.push(-1) ;
   else
   {
       q.push(1) ;
       q.push(-1) ;
   }
   for(; !q.empty() ; siz = q.size() , depth ++)
   {
       while(siz --)
       {
           int cur = q.front() ; q.pop() ;
           if(depth == s1.size())
           {
               poss.pb(cur) ;
               continue ;
           }
           if(s2[depth] == '+') q.push(cur + 1) ;
           else if(s2[depth] == '-') q.push(cur -1) ;
           else
           {
               q.push(cur + 1) ;
               q.push(cur -1) ;
           }
       }
   }
}

int main(){
   IOS
   cin >> s1 >> s2 ;
   rep(i , 0 , s1.size())
   {
      pos += ((s1[i] == '+') ? 1 : -1 ) ;
   }
   bfs() ;
   double x = count(poss.begin() , poss.end() , pos) ;
   double y =  poss.size() ;
   double ans =  x / y ;
   cout << setprecision(20) << ans ;
}
