#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int a, b, c, d;
    cin >> a >> b >> c >> d;
 
    int rick = b, morty = d;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            rick = b + i * a ;
            morty = d + j * c ;
            if(rick == morty){
                cout << rick ;
                return 0 ;
            }
            if(morty > rick) break ;
        }
    }
 
    cout << -1 ;
}
