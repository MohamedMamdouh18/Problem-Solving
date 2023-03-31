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
vector<int> nums;

void GO() {
    int n ;
    cin >> n ;
    cout << nums[n-1] << el;
}

int main() {
    IOS
    PREC
    for (int i = 1; i < 3000; ++i) {
        if (!(i % 3 == 0 || i % 10 == 3)) nums.pb(i);
    }

    int tc = 1;
    cin >> tc;
    while (tc--) {
        GO();
    }
}
