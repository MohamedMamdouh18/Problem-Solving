#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pll pair<ll , ll>
#define llm LONG_LONG_MAX
#define pb push_back
#define pi pair<int,int>
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
vector <vector<pair<int,ll>>> adj_list ;
 
void Dijkstra(int src ,vector<ll> &dist, vector<int> &previ)
{
    dist[src] = 0 ;
    priority_queue<pair<int,ll>> q ;
    q.push({0,src}) ;
    while(!q.empty())
    {
        ll v = q.top().second;
        ll d_v = - q.top().first;
        q.pop();
        if(d_v > dist[v]) continue;
        for (auto edge : adj_list[v]) {
            ll to = edge.first;
            ll len = edge.second;
 
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                previ[to] = v;
                q.push({- dist[to], to});
            }
        }
    }
}
 
void solve()
{
    int n , m ;
    cin >> n >> m ;
    adj_list.resize(n) ;
    vector<ll> dist(n , llm) ;
    vector<int> previ(n , -1) ;
    while(m --)
    {
        int x , y, w ;
        cin >> x >> y >> w ;
        x -- , y -- ;
        adj_list[x].pb({y , w}) ;
        adj_list[y].pb({x , w}) ;
    }
    Dijkstra(0, dist , previ) ;
    if(previ[n-1] == -1) cout << -1 ;
    else
    {
        vector<int> ans ;
        for(ll i=n-1;i!=0;i=previ[i]) ans.push_back(i);
        ans.pb(0) ;
        reverse(ans.begin() , ans.end()) ;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] + 1<< " " ;
        }
    }
}
 
int main() {
    IOS
    solve();
 
}
