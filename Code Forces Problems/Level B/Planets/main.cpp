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
vector<vector<pair<int , ll>>> times ;

ll binary_search(int ind , ll val)
{
    int n = times[ind].size() ;
    int l = 0 , r = n-1 ;
    while(l <= r)
    {
        int mid = (l+r)/2 ;
        if(times[ind][mid].fi == val) return times[ind][mid].se ;
        else if(times[ind][mid].fi < val) l = mid + 1 ;
        else if(times[ind][mid].fi > val) r = mid - 1 ;
    }
    return 0 ;
}

void Dijkstra(int src)
{
    int n = adj_list.size() ;
    vector<ll> dist(n,llm) ;
    vector<int> previ(n , -1) ;
    dist[src] = binary_search(0 , 0) ;

    priority_queue<pair<ll , int>> q ;
    q.push({0 , src}) ;
    while(!q.empty())
    {
        int from = q.top().second;
        ll dis = - q.top().fi;
        q.pop() ;
        if(dis > dist[from]) continue ;

        for(auto edge : adj_list[from]) {
            ll len = edge.fi ;
            int to  = edge.se ;
            ll new_route = len + dist[from] ;
            if(to != n-1)new_route += binary_search(to , new_route) ;
            if(dist[to] > new_route)
            {
                dist[to] = new_route ;
                previ[to] = from ;
                q.push({-new_route , to}) ;
            }
        }
    }
    cout << (dist[n-1] == llm ? -1 : dist[n-1]) ;
}

int main() {
    IOS
    int n , m ;
    cin >> n >> m;
    adj_list.resize(n) ;
    times.resize(n) ;
    while(m --)
    {
        int x , y, w ;
        cin >> x >> y >> w ;
        x -- , y -- ;
        adj_list[x].pb({w , y}) ;
        adj_list[y].pb({w , x}) ;
    }
    for (int i = 0; i < n; ++i) {
        int t ;
        cin >> t ;
        while(t --)
        {
            int l ;
            cin >> l ;
            times[i].pb({l , 1}) ;
        }
        ll sec = 1 ;
        for (int j = times[i].size()-1; j >= 0; j --) {
            times[i][j].se = sec ;
            if(j > 0 && (times[i][j].fi == (times[i][j-1].fi+1))) sec ++ ;
            else sec = 1 ;
        }
    }
    Dijkstra(0) ;
}
