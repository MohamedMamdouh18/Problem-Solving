#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, ans = 0, num;
    cin >> n;
    vector<int> key(n);
    for (int i = 0; i < n; ++i) cin >> key[i];

    sort(all(key));
    num = key[0];
    for (int i = 0; i < n; ++i) {
        if (num == key[i]) num++;
        else {
            ans += key[i] - num;
            num = key[i] + 1;
        }
    }
    cout << ans;
}
