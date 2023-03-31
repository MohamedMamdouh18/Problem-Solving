
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n;
    cin >> n;
    vector<int> visit(n + 1, 0);
    vector<int> enter(n + 1);
    vector<int> exit(n + 1);

    for (int i = 0; i < n; ++i) cin >> enter[i];
    for (int i = 0; i < n; ++i) cin >> exit[i];

    int j = 0, fine = 0, last = enter[0];
    for (int i = 0; i < exit.size(); ++i) {
        visit[exit[i]]++;
        if (last != exit[i]) fine++;
        else {
            while (j < visit.size() && visit[enter[j]]) j++;
            last = enter[j];
        }
    }
    cout << fine;
}
