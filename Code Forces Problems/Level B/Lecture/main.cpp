#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)
 
 
int main() {
    IOS
    map<string , string> lang ;
    int n , m ;
    string s1 ; string s2 ;
    cin >> n >> m ;
    while(m--)
    {
        cin >> s1 >> s2 ;
        lang[s1] = s2 ;
    }
    s1.clear() ;
    while(n--)
    {
        cin >> s2 ;
        if(lang[s2].size() < s2.size())
        {
            s1 += lang[s2] + " " ;
        }
        else
        {
            s1 += s2 + " " ;
        }
    }
 
    cout << s1 ;
}
