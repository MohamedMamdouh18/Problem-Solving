#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define all(a) a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, init = 1, start = 0, end = 0;
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
            if (num[i] == init && init == i + 1) init++;
            else if (init == i + 1) start = i;
            else if (num[i] == init) end = i;
        }
        reverse(num.begin() + start, num.begin() + end + 1);
        for (int i = 0; i < n; ++i) cout << num[i] << " ";
        cout << el;
    }
}
