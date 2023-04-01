#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t;
    stack<int> st;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (x == 1) {
            int n;
            cin >> n;
            st.push(n);
        } else if (x == 2) {
            if (!st.empty()) st.pop();
        } else {
            if (st.empty()) cout << "Empty!" << el;
            else cout << st.top() << el;
        }
    }
}
