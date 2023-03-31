
#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    map<char , int> cost ; int total = 0 ;
    cin >> cost['1']>> cost['2']>> cost['3']>> cost['4'] ;
    string s ;
    cin >> s ;
    rep(i , 0 , s.size())
    {
        total += cost[s[i]] ;
    }
    cout <<total ;
}
