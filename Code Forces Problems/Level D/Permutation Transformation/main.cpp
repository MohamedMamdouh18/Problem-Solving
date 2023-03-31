#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> num, dep;

void traverse(int start, int end, int ind, int depth) {
    if (end - start <= 0) return;
    int maxi = INT_MIN, ind2;
    for (int i = start; i < ind; i++) {
        if (num[i] > maxi) {
            maxi = num[i];
            ind2 = i;
        }
    }
    if (maxi != INT_MIN) {
        dep[ind2] = depth + 1;
        traverse(start, ind - 1, ind2, depth + 1);
    }

    maxi = INT_MIN;
    for (int i = ind + 1; i <= end; i++) {
        if (num[i] > maxi) {
            maxi = num[i];
            ind2 = i;
        }
    }
    if (maxi != INT_MIN) {
        dep[ind2] = depth + 1;
        traverse(ind + 1, end, ind2, depth + 1);
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, maxi = INT_MIN, ind;
        cin >> n;
        num.resize(n), dep.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
            if (num[i] > maxi) {
                maxi = num[i];
                ind = i;
            }
        }
        dep[ind] = 0;
        traverse(0, n - 1, ind, 0);
        for (int i = 0; i < n; ++i) cout << dep[i] << " ";
        cout << el;
    }
}
