#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, between = 0;
        cin >> n;
        vector<string> bigrams(n - 2);
        for (int i = 0; i < bigrams.size(); ++i) cin >> bigrams[i];


        for (int i = 0; i < bigrams.size() - 1; ++i) {
            if (bigrams[i][1] != bigrams[i + 1][0]) {
                between = 1;
                string toInsert;
                toInsert.push_back(bigrams[i][1]);
                toInsert.push_back(bigrams[i + 1][0]);
                bigrams.insert(bigrams.begin() + i + 1, toInsert);
                break;
            }
        }
        if (!between) {
            if (bigrams[n - 3][1] == 'a') bigrams.pb("aa");
            else bigrams.pb("bb");
        }
        string s;

        s += bigrams[0];
        for (int i = 1; i < bigrams.size(); ++i) s.push_back(bigrams[i][1]);

        cout << s << el;
    }
}
