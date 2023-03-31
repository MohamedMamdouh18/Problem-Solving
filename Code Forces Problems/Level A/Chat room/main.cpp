#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    string s;
    cin >> s ;
    string ans = "hello" ;int j = 0 ;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == ans[j]) j ++ ;
        if(j >= ans.size())
        {
            cout << "YES" ;
            return 0 ;
        }
    }
    cout << "NO" ;
}
