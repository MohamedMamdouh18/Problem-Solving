#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    string s ;
    cin >> s ;
    int q, op, pos, l, r;
    cin >> q ;
    vector<set<int>> occurences(26) ;
    for (int i = 0; i < s.size(); ++i) {
        occurences[s[i]-'a'].insert(i) ;
    }
 
    while (q--) {
        cin >> op;
        if (op == 1) {
            char s1;
            cin >> pos >> s1;
            pos-- ;
            occurences[s[pos]-'a'].erase(occurences[s[pos]-'a'].find(pos)) ;
            s[pos] = s1 ;
            occurences[s[pos]-'a'].insert(pos) ;
        } else {
            int ans = 0 ;
            cin >> l >> r;
            l--, r--;
            for (auto &ch : occurences) {
                auto ind = ch.lower_bound(l) ;
                if(ind != ch.end() && *ind <= r) ans ++ ;
            }
            cout << ans << el;
        }
    }
}
