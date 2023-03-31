#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, s;
    cin >> n >> s;
    map<int, int> sell;
    map<int, int> buy;
    priority_queue<pair<int, int>> outputSell;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> sell_pq;
    priority_queue<pair<int, int>> buy_pq;

    char t;
    int p, q;
    for (int i = 0; i < n; ++i) {
        cin >> t >> p >> q;
        if (t == 'S') {
            if (sell.find(p) == sell.end()) {
                sell[p] = 0;
            }
            sell[p] += q;
        } else {
            if (buy.find(p) == buy.end()) {
                buy[p] = 0;
            }
            buy[p] += q;
        }
    }

    for (auto it: sell) sell_pq.push(it);
    for (auto it: buy) buy_pq.push(it);

    for (int i = 0; i < s; ++i) {
        if (sell_pq.empty()) break;
        outputSell.push(sell_pq.top()) ;
        sell_pq.pop();
    }

    while (!outputSell.empty()){
        cout << "S " << outputSell.top().fi << " " << outputSell.top().se << el;
        outputSell.pop() ;
    }

    for (int i = 0; i < s; ++i) {
        if (buy_pq.empty()) break;
        cout << "B " << buy_pq.top().fi << " " << buy_pq.top().se << el;
        buy_pq.pop();
    }
}
