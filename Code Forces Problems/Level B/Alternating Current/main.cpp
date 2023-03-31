#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    string s ;
    cin >> s ;
    stack<char> st ;
    for (int i = 0; i < s.size(); ++i) {
        if(st.empty())st.push(s[i]) ;
        else{
            if(s[i] == st.top()) st.pop();
            else st.push(s[i]) ;
        }
    }

    cout << (st.empty() ? "Yes" : "No") ;
}
