#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)
 

int main() {
    IOS
    int n ;
    cin >> n ;
    queue <pair<ll , ll>> q ;
    q.push(mp(0 , 0)) ;
    while(!q.empty())
    {
        ll val = q.front().first ;
        ll c = q.front().second ;
        q.pop() ;
        if(val >= n && c == 0)
        {
            cout << val ;
            return 0 ;
        }
        q.push(mp(val*10 + 4 , c - 1) );
        q.push(mp(val*10 + 7 , c + 1) );
    }
}
 
