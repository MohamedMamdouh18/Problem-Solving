#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll , ll>
#define llm LONG_LONG_MAX
#define pb push_back
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector <vector<pair<ll , int>>> adj_list ;
vector <pair<ll , int>> trains ;

void Dijkstra(int src)
{
    int n = adj_list.size() ;
    vector<ll> dist(n,llm) ;
    vector<int> previ(n , -1) ;
    vector<int> routes(n,0) ;
    dist[src] = 0 ;
    priority_queue<pair<ll , int>> q ;
    q.push({0 , src}) ;
    while(!q.empty())
    {
        int from = q.top().second;
        int dis = - q.top().fi;
        q.pop() ;
        if(dis > dist[from]) continue ;

        for(auto edge : adj_list[from]) {
            ll len = edge.fi ;
            int to  = edge.se ;
            ll new_route = len + dist[from] ;
            if(dist[to] > new_route)
            {
                len = dist[to] = new_route ;
                routes[to] = 1;
                previ[to] = from ;
                q.push({-new_route , to}) ;
            }
            else if(dist[to] == len + dist[from]) routes[to] ++ ;
        }
    }

    int ans = 0 ;
    for(auto train : trains)
    {
        int to = train.se ;
        ll len = train.fi ;
        if(dist[to] < len) ans ++ ;
        else if(dist[to] == len && routes[to] > 1)
        {
            ans ++ ;
            routes[to] -- ;
        }
    }
    cout << ans ;
}

int main() {
    IOS
    int n , m  , k;
    cin >> n >> m >> k;
    adj_list.resize(n) ;

    while(m --)
    {
        int x , y, w ;
        cin >> x >> y >> w ;
        x -- , y -- ;
        adj_list[x].pb({w , y}) ;
        adj_list[y].pb({w , x}) ;
    }
    for (int i = 0; i < k; ++i) {
        int x , w ;
        cin >> x >> w ;
        x -- ;
        adj_list[x].pb({w, 0}) ;
        adj_list[0].pb({w , x}) ;
        trains.pb({w , x}) ;
    }
    Dijkstra(0) ;
}
