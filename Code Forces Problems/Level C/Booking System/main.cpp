#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define el "\n"
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 101, M = 20, INF = 1e-18;


void LIGHT_BLUE() {
    int n, k, ans_money = 0, ans_request = 0;
    cin >> n;
    vector<pair<int, pair<int, int>>> requests(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        requests[i] = {y, {x, i + 1}};
    }
    cin >> k;
    set<pair<int, int>> table;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        table.emplace(x, i + 1);
    }
    sort(requests.rbegin(), requests.rend());
    vector<pair<int, int>> ans_vector;
    for (int i = 0; i < requests.size(); ++i) {
        int money = requests[i].first, number = requests[i].second.first, index = requests[i].second.second;
        if (table.empty())
            break;
        auto cur_table = table.lower_bound({number, -1});
        if (cur_table != table.end()) {
            ans_money += money;
            ans_request++;
            ans_vector.emplace_back(index, cur_table->second);
            table.erase(cur_table);
        }
    }
    sort(all(ans_vector));
    cout << ans_request << " " << ans_money << el;
    for (int i = 0; i < ans_vector.size(); ++i) {
        cout << ans_vector[i].first << " " << ans_vector[i].second << el;
    }
}

int main() {
    PREC
    IOS
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        LIGHT_BLUE();
    }
}
