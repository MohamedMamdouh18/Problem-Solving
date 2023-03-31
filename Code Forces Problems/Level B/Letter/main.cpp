#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
int freq[100001] ;

void solve() {
    string s1 , s2 ;
    getline(cin , s1) ;
    getline(cin , s2) ;
    for (int i = 0; i < s1.size(); ++i) freq[s1[i]] ++ ;
    for (int i = 0; i < s2.size(); ++i) {
        freq[s2[i]] -- ;
        if(s2[i] != ' ' && freq[s2[i]] < 0){
            cout << "NO";
            return;
        }
    }
    cout << "YES" ;
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
