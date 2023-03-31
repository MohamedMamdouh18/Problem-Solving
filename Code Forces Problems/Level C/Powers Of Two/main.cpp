#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;
 
void GREEN() {
    int n, k, ones = 0;
    cin >> n >> k;
    bitset<30> rep = n;
    vector<int> nums;
    map<int, int> freq;
    for (int i = 0; i < 30; ++i) {
        ones += rep[i];
        if (rep[i]) {
            int cur = pow(2, i);
            nums.pb(cur);
            freq[cur]++;
        }
    }
    if (ones > k) {
        cout << "NO" ;
        return;
    }
    int ptr = 0;
    while (ones != k && ptr < nums.size()) {
        int cur = nums[ptr];
        if (freq[cur] == 0 || cur == 1) {
            ptr++;
            continue;
        }
 
        ones++;
        freq[cur]--;
        if(!freq[cur]) freq.erase(cur) ;
        freq[cur / 2] += 2;
        nums.pb(cur / 2);
    }
 
    if (ones == k) {
        cout << "YES" << el;
        for(auto item : freq){
            for (int i = 0; i < item.second; ++i) {
                cout << item.first << " " ;
            }
        }
    } else cout << "NO";
 
}
 
int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
