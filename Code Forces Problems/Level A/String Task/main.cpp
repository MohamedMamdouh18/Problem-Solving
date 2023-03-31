#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main() {
    IOS
    string s ;
    cin >> s ;
    vector<char> ans ;
    for (int i = 0; i < s.size(); ++i) {
        char a = tolower(s[i]) ;
        if(a!='a' && a!='i' && a!='e' && a!='o' && a!='u' && a!='y') ans.pb(a) ;
    }
    for (int i = 0; i < ans.size(); ++i) {
       cout <<'.' <<ans[i];
    }
}
