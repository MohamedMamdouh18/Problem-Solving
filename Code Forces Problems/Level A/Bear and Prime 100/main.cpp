#include <bits/stdc++.h>

using namespace std;

#define el "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int> prime;

void sieve(int limit) {
    bool mark[limit + 1];
    memset(mark, true, sizeof(mark));
    for (int p = 2; p * p < limit; ++p) {
        if (mark[p])
            for (int i = p * 2; i < limit; i += p) {
                mark[i] = false;
            }
    }
    for (int p = 2; p < limit; ++p) {
        if (mark[p]) prime.push_back(p);
    }
}

int main() {
    sieve(100);
    string answer;
    int i = 0, j = 0, factors = 0;
    cout << prime[i] << el;
    while (cin >> answer) {
        if (answer == "yes") {
            factors++;
            if (prime[i] < 8) {
                j++;
                cout << prime[i] * prime[i] << el;
                cin >> answer;
                if (answer == "yes") factors++;
            }
        }
        if (factors >= 2) {
            cout << "composite" << el;
            return 0;
        }
        i++;
        if (i + j == 20) break;
        cout << prime[i] << el;
    }
    cout << "prime" << el;
}
