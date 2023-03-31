#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    ll n , x , time = 0 , ans = 0;
    priority_queue<ll , vector<ll> , greater<>> pq ;
    cin >> n ;
    for (int i = 0; i < n; ++i) {
        cin >>  x ;
        pq.push(x) ;
    }
    while (!pq.empty()){
        if(time <= pq.top()){
            ans ++ ;
            time += pq.top() ;
        }
        pq.pop() ;
    }
    cout << ans ;
}
