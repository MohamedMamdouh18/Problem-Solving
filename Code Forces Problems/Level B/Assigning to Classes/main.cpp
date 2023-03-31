#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> student(2*n);
        for (int i = 0; i < n * 2; ++i) cin >> student[i];
        sort(all(student));
        cout << abs(student[n] - student[n - 1]) << el;
    }
}
