#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll> original, spare;
int ans = 0;

void mergeArray(int start1, int end1, int start2, int end2) {
    int ptr1 = start1, ptr2 = start2, indx = 0;
    while (ptr1 <= end1 || ptr2 <= end2) {
        if (ptr1 > end1 || (ptr2 <= end2 && original[ptr2] <= original[ptr1])) {
            spare[indx++] = original[ptr2++];
        } else {
            spare[indx++] = original[ptr1++];
            if (ptr2 <= end2)ans += end2 - ptr2 + 1;
        }
    }

    for (int i = 0; i < indx; ++i) original[i + start1] = spare[i];
}

void mergeSort(int l, int r) {
    if (r - l < 1) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    mergeArray(l, mid, mid + 1, r);
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        original.resize(m);
        spare.resize(m);
        for (int i = 0; i < m; ++i) cin >> original[i];
        mergeSort(0, m - 1);
        cout << ans << el;
        ans = 0;
    }
}
