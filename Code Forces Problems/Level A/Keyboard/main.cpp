#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    string origin = "qwertyuiopasdfghjkl;zxcvbnm,./" ;
    map <char , char > to_left ;
    map <char , char > to_right ;
    rep(i , 1 , 10)
    {
        to_left[origin[i]] = origin[i - 1];
        to_left[origin[i + 10]] = origin[i - 1 + 10];
        to_left[origin[i + 20]] = origin[i - 1 + 20];
    }
    rep(i , 0 , 9)
    {
        to_right[origin[i]] = origin[i + 1];
        to_right[origin[i + 10]] = origin[i + 1 + 10];
        to_right[origin[i + 20]] = origin[i + 1 + 20];
    }
    string s ; char mov ;
    cin >> mov >> s ;
    if(mov == 'R')
    {
        rep(i , 0 , s.size())
        {
            s[i] = to_left[s[i]] ;
        }
    }
    else
    {
        rep(i , 0 , s.size())
        {
            s[i] = to_right[s[i]] ;
        }
    }
    cout << s ;
}
