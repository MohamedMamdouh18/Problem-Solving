#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void solve() {
    stack<char> st ;
    string s ; int n ;
    cin >>n >> s ;
    for (int i = 0; i < s.size(); ++i) {
        st.push(s[i]) ;
        int j = i + 1;
        while (! st.empty() && j < s.size() && s[j] != st.top()) st.pop() , j ++ , i++;
    }
    cout << st.size() ;
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
}
