#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);

void GO() {
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    int i = s1.size() - 1, j = s2.size() - 1;
    while (s1[i] == s2[j] && i >= 0 && j >= 0)i--, j--;

    cout << i + j + 2;
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GO();
    }
}
