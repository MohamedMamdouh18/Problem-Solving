#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int one, two, three;

void inc(char c) {
    switch (c) {
        case '1' :
            one++;
            break;
        case '2' :
            two++;
            break;
        case '3' :
            three++;
    }
}

void dec(char c) {
    switch (c) {
        case '1' :
            one--;
            break;
        case '2' :
            two--;
            break;
        case '3' :
            three--;
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        one = 0, two = 0, three = 0;
        int mini = INT_MAX;

        string s;
        cin >> s;
        for (char i: s) inc(i);

        if (one == 0 || two == 0 || three == 0) {
            cout << 0 << el;
            continue;
        }

        int r = 2;
        one = 0, two = 0, three = 0;
        inc(s[0]), inc(s[1]), inc(s[2]);

        for (int l = 0; l < s.size(); ++l) {
            while ((one == 0 || two == 0 || three == 0) && r < s.size()) {
                r++;
                inc(s[r]);
            }
            if(!(one == 0 || two == 0 || three == 0))mini = min(mini, r - l + 1);
            dec(s[l]);
        }
        cout << mini << el;
    }
}
