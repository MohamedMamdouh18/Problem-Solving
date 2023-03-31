#include <bits/stdc++.h>
using namespace std ;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    map<string , int > cost ;
    cost["Tetrahedron"] = 4 ;
    cost["Cube"] = 6 ;
    cost["Octahedron"] = 8 ;
    cost["Dodecahedron"] = 12 ;
    cost["Icosahedron"] = 20 ;
    string s ;
    int total = 0 , n;
    cin >> n ;
    while(n--)
    {
        cin >> s ;
        total += cost[s] ;
    }
    cout << total ;
}
