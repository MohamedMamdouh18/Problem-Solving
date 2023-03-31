#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define all(a) a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, ans = 0;
    cin >> n;
    vector<int> ice(n), after(n);
    for (int i = 0; i < n; ++i) cin >> ice[i];
    sort(all(ice));

    int r = n - 1;
    if (n & 1) {
        for (int i = 0; i < n; i += 2) after[i] = ice[r--];
        for (int i = 1; i < n; i += 2) after[i] = ice[r--];
    } else {
        for (int i = 1; i < n; i += 2) after[i] = ice[r--];
        for (int i = 0; i < n; i += 2) after[i] = ice[r--];
    }

    for (int i = 1; i < n - 1; ++i) if (after[i] < after[i - 1] && after[i] < after[i + 1]) ans++;

    cout << ans << el;
    for (int i = 0; i < n; ++i) cout << after[i] << " ";
}
