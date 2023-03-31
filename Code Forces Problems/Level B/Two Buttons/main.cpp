#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
vector<int> vis(10001) ;
int n , m ;
 
int bfs(int node)
{
    int depth = 0 , siz = 0;
    queue<int> q ;
    q.push(node) ;
    for(; !q.empty() ; depth ++ ,  siz = q.size())
    {
        while(siz --)
        {
            int cur = q.front() ; q.pop() ;
            vis[cur] = 1 ;
            if(cur == m) return depth-1 ;
 
            int child = cur - 1 ;
            if(child > 0 && !vis[child]) q.push(child) ;
            child = cur * 2 ;
            if(child < 10001&& !vis[child]) q.push(child) ;
 
        }
    }
}
 
int main(){
   IOS
   cin >> n >> m ;
   if(m < n) cout << n - m ;
   else cout << bfs(n) ;
}
