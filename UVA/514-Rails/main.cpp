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
const ll mod = 1e9 + 7, N = 1e6, M = 20, INF = LONG_LONG_MAX;


void GREEN() {
    int n;
    while (cin >> n && n) {
        vector<int> perm(n);
        while (cin >> perm[0] && perm[0]) {
            int cur = 1;
            stack<int> coach;
            for (int i = 0; i < n; ++i) {
                if (i > 0)
                    cin >> perm[i];
                if (cur == perm[i]) {
                    cur++;
                    continue;
                }
                while (cur <= n && cur != perm[i]) {
                    if (!coach.empty() && coach.top() == perm[i]) {
                        break;
                    }
                    coach.push(cur++);
                }
                if (!coach.empty() && coach.top() == perm[i])
                    coach.pop();
                if (cur == perm[i])
                    cur++;
            }
            cout << ((coach.empty()) ? "Yes" : "No") << el;
        }
        cout << el ;
    }
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
