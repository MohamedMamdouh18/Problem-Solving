#include <bits/stdc++.h>
 
using namespace std;
 
const int N = (int) 2e5 + 10;
 
int n;
long long a[N];
map<long long,int> mp;
vector<int> ans;
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        ++mp[a[i]];
    }
    for (int i = 0; i < n; ++i) {
        if((sum - a[i]) & 1) continue;
        mp[a[i]]--;
        sum -= a[i];
        if(mp[sum / 2]) {
            ans.push_back(i + 1);
        }
        sum += a[i];
        mp[a[i]]++;
    }
    cout << (int) ans.size() << '\n';
    for(auto x : ans) cout << x << ' ';
    return 0;
}
