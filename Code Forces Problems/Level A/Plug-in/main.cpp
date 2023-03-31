
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define pb push_back
#define mp make_pair
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    string n;
    cin >> n ;
    stack <char> st1 ;
    rep(i , 0 , n.size())
    {
        if(!st1.empty() && n[i] == st1.top())
        {
            st1.pop() ;
        }
        else st1.push(n[i]) ;
    }
    stack <char> st2 ;
    while(!st1.empty())
    {
        st2.push(st1.top()) ;
        st1.pop() ;
    }
    while(!st2.empty())
    {
        cout << st2.top() ;
        st2.pop() ;
    }
}
