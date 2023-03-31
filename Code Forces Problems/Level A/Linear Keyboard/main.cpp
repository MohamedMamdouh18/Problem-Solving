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
    int t ;
    cin >> t ;
    while (t--){
        map<char,int> keyboard ;
        string word ;
        int last , time = 0;
        for (int i = 0; i < 26; ++i) {
            char x ;
            cin >> x ;
            keyboard[x] = i+ 1 ;
        }
        cin >> word ;
        last = keyboard[word[0]] ;
        for (int i = 1; i < word.size(); ++i) {
            int crnt = keyboard[word[i]] ;
            time += abs(last - crnt) ;
            last = crnt ;
        }
        cout << time << el ;
    }
}
