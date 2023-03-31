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
    int n, superior = 0;
    cin >> n;
    int score[n][5];
    for (int i = 0; i < n; ++i) {
        int better = 0;
        for (int j = 0; j < 5; ++j) {
            cin >> score[i][j];
            if (i > 0) better += score[i][j] < score[superior][j];
        }
        if (i > 0)if (better >= 3) superior = i;
    }
    for (int i = 0; i < n; ++i) {
        if (i != superior) {
            int better = 0;
            for (int j = 0; j < 5; ++j) better += score[i][j] < score[superior][j];
            if (better >= 3) {
                cout << -1 << el;
                return;
            }
        }
    }
    cout << superior + 1 << el;
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
