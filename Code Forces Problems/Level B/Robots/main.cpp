#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
char field[5][5] ;
int n , m ;
vector<pair<int , int>> robots ;
 
bool moveRobots(int x , int y){
    for (int i = 0; i < robots.size(); ++i) {
        int newX = robots[i].fi + x , newY = robots[i].se + y ;
        if(newX < 0 || newX > n-1 || newY < 0 || newY > m-1) return false ;
    }
    return true;
}
 
void possibleMove(){
        int x = -robots[0].fi , y = -robots[0].se ;
        if(moveRobots(x , y)){
            cout << "YES" << el ;
            return;
        }
    
    cout << "NO" << el ;
}
 
 
int main() {
    IOS
    PREC
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m ;
        robots.clear() ;
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> field[i][j] ;
                if(field[i][j] == 'R') robots.emplace_back(i , j) ;
            }
        }
        possibleMove() ;
 
    }
}
