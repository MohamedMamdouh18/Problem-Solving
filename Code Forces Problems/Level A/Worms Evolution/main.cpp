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
    int n;
    cin >> n;
    vector<int> worms(n);
    for (int i = 0; i < n; ++i) cin >> worms[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;;
            for (int k = 0; k < n; ++k) {
                if (k == j || k == i) continue;
                if (worms[i] == worms[j] + worms[k]) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1;
                    return 0;
                }
            }
        }
    }

    cout << -1;
}
