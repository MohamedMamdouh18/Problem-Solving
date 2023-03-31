#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e5;
bool even;
int n, m;
int ptr1 = 0, ptr2;
double mean;

void GREEN() {
    cin >> n >> m;
    vector<int> ans(n);
    vector<int> siz(m);
    if(m == 1){
        for (int i = 0; i < n; ++i) cout << 1 << el;
        return;
    }
    mean = (double) (m+1) / 2;
    even = !(m & 1);
    ptr2 = m + 1;
    for (int i = 0; i < n; i++) {
        if (ptr1 == 0) {
            if (even) ptr1 = m / 2;
            else ptr1 = (m + 1) / 2;
        }
        if (ptr2 == m + 1) {
            if (even)ptr2 = m / 2 + 1;
            else ptr2 = (m + 1) / 2 + 1;
        }
        if (siz[ptr1 - 1] == siz[ptr2 - 1]) {
            if (abs(abs(ptr1 - mean) - abs(ptr2 - mean)) < 1e-4 || abs(ptr1 - mean) < abs(ptr2 - mean)) {
                ans[i] = ptr1;
                siz[ptr1 - 1]++;
                ptr1--;
            } else if (abs(ptr1 - mean) > abs(ptr2 - mean)) {
                ans[i] = ptr2;
                siz[ptr2 - 1]++;
                ptr2++;
            }
        } else {
            if (siz[ptr1 - 1] < siz[ptr2 - 1]) {
                ans[i] = ptr1;
                siz[ptr1 - 1]++;
                ptr1--;
            } else {
                ans[i] = ptr2;
                siz[ptr2 - 1]++;
                ptr2++;
            }
        }

    }
    for (int i = 0; i < n; ++i) cout << ans[i] << el;
}

int main() {
    IOS
    PREC
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
