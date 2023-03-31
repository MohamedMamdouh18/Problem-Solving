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
    int n, c1, c2;
    cin >> n;
    c1 = n / 3, c2 = c1 + 1;
    if(c1 + 2 * c2 == n) cout << c1 << " " << c2 << el ;
    else if(c1 + 2 * c1 == n) cout << c1 << " " << c1 << el ;
    else if(c2 + 2 * c1 == n) cout << c2 << " " << c1 << el ;
    else if(c2 + 2 * c2 == n) cout << c2 << " " << c2 << el ;

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
