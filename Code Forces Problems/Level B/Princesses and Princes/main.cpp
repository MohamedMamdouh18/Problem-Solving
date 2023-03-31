#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    int n, m, x;
    cin >> n;
    vector<bool> prince(n + 1, true);
    int free = 1, lastAlone = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        vector<int> desire(m);
        for (int j = 0; j < m; ++j) cin >> desire[j];
        bool flag = false;
        for (int j = 0; j < m; ++j) {
            if (prince[desire[j]]) {
                prince[desire[j]] = false;
                flag = true;
                break;
            }
        }
        if (!flag) {
            lastAlone = min(i + 1, lastAlone);
        }
        while (!prince[free]) free++;
    }
    if (free == n + 1)cout << "OPTIMAL" << el;
    else {
        cout << "IMPROVE" << el;
        cout << lastAlone << " " << free << el;
    }
}

int main() {
    IOS
    PREC

    int tc = 1;
    cin >> tc;
    while (tc--) {
        GO();
    }
}
