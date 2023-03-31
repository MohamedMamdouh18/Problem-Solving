#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<vector<int>> adj_list ;
vector<int> vis ;
vector<int> price ;
int n , m , gold = INT_MAX;

void dfs(int node) {
    vis[node] = 1 ;
    gold = min(gold , price[node]) ;
    for (int i = 0; i < adj_list[node].size(); ++i) {
        int child = adj_list[node][i] ;
        if(!vis[child]) dfs(child) ;
    }
}

int main() {
    IOS
    cin >> n >> m ;
    ll total_gold = 0 ;
    adj_list.resize(n) ;
    price.resize(n) ;
    vis.resize(n , 0) ;
    for (int i = 0; i < n; ++i) {
        cin >> price[i] ;
    }
    for (int i = 0; i < m; ++i) {
        int x , y ;
        cin >> x >> y;
        x-- , y -- ;
        adj_list[x].pb(y) ;
        adj_list[y].pb(x) ;
    }
    for (int i = 0; i < n; ++i) {
        if(!vis[i])
        {
            dfs(i) ;
            total_gold+= gold ;
            gold = INT_MAX ;
        }
    }
    cout << total_gold ;

}
