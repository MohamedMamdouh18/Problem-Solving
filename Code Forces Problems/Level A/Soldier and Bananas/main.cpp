#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n, w, borrow, buy = 0;
    cin >> k >> n >> w;
    for (int i = 1; i <= w; ++i) buy += i * k;
    borrow = (buy > n) ? buy - n : 0;
    cout << borrow;
}
