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
    int n, m, mx = INT_MIN;
    cin >> n >> m;
    map<string, int> members;
    vector<int> final;
    vector<pair<int, int>> bad;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        members[s] = i;
    }

    for (int i = 0; i < m; ++i) {
        string s, z;
        cin >> s >> z;
        bad.pb({members[s], members[z]});
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> current;
        int valid = 1;
        for (int i = 0; i < n; ++i) if (mask & (1 << i)) current.pb(i);

        for (int i = 0; i < current.size(); ++i) {
            for (int j = i + 1; j < current.size(); ++j) {
                for (int k = 0; k < bad.size(); ++k) {
                    if (bad[k].fi == current[i] && bad[k].se == current[j]) valid = 0;
                    if (bad[k].fi == current[j] && bad[k].se == current[i]) valid = 0;
                    if (!valid) break;
                }
                if (!valid) break;
            }
            if (!valid) break;
        }

        if (!valid) continue;

        if ((int) current.size() > mx) {
            mx = current.size();
            final = current;
        }
    }

    cout << final.size() << el;
    for (auto it: members) {
        for (int i = 0; i < final.size(); ++i) {
            if (final[i] == it.se) {
                cout << it.fi << el;
                break;
            }
        }
    }
}
