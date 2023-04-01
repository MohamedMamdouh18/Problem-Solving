#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e5 + 1;
char grid[101][101];
bool state[101][101] ;
int cost[101][101] ;
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct node {
    int i, j;
    bool closed = true;
};

int bfs(pair<int, int> start) {
    queue<node> q;
    q.push({start.fi , start.se , true});
    cost[start.fi][start.se] = 0 ;
    state[start.fi][start.se] = false ;
    while (!q.empty()) {
        node cur = q.front();

        q.pop();
        for (int i = 0; i < 4; ++i) {
            int newX = cur.i + dx[i];
            int newY = cur.j + dy[i];
            if (newX >= n || newY >= m || newX < 0 || newY < 0) return cost[cur.i][cur.j]+1;
            else{
                if(!state[newX][newY] == cur.closed){
                    if((grid[newX][newY] == '.' || (grid[newX][newY] == 'D' && !cur.closed)) && cost[newX][newY] > cost[cur.i][cur.j] + 1 ){
                        cost[newX][newY] = cost[cur.i][cur.j] + 1 ;
                        q.push({newX , newY , cur.closed}) ;
                    }else if(grid[newX][newY] == 'O' && cost[newX][newY] > cost[cur.i][cur.j] + 1 ){
                        cost[newX][newY] = cost[cur.i][cur.j] + 1 ;
                        state[newX][newY] = true ;
                        q.push({newX , newY , false}) ;
                    }else if(grid[newX][newY] == 'C' && cost[newX][newY] > cost[cur.i][cur.j] + 1 ) {
                        cost[newX][newY] = cost[cur.i][cur.j] + 1;
                        q.push({newX, newY, true});
                    }
                }else{
                    if(cur.closed){
                        if(grid[newX][newY] == '.' && cost[newX][newY] > cost[cur.i][cur.j] + 1 ){
                            cost[newX][newY] = cost[cur.i][cur.j] + 1 ;
                            state[newX][newY] = false ;
                            q.push({newX , newY , cur.closed}) ;
                        }
                    }else{
                        if(grid[newX][newY] == 'C') {
                            cost[newX][newY] = cost[cur.i][cur.j] + 1;
                            state[newX][newY] = false ;
                            q.push({newX, newY, true});
                        }else if(grid[newX][newY] != 'W'){
                            cost[newX][newY] = cost[cur.i][cur.j] + 1 ;
                            state[newX][newY] = true ;
                            q.push({newX , newY , cur.closed}) ;
                        }
                    }
                }
            }

        }
    }
    return -1;
}

void GREEN() {
    while (cin >> n >> m && n != -1) {
        pair<int, int> start;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                cost[i][j] = 1e9 ;
                state[i][j] = false ;
                if (grid[i][j] == 'H') {
                    start = {i, j};
                    grid[i][j] = '.';
                }
            }
        }
        cout << bfs(start) << el;
    }
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
