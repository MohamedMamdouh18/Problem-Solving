#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    map<string , int> mp ;
    priority_queue<pair<int , string>> pq ;
    int t , num = 0;
    cin >> t ;
    while(t --){
        string s ;
        cin >> s ;
        mp[s] = num ;
        num ++ ;
    }
 
    for(auto it : mp) pq.push({it.se , it.fi}) ;
 
    while(!pq.empty()){
        cout << pq.top().se << el ;
        pq.pop() ;
    }
}
