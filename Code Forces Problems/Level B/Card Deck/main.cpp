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
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> cards(n);
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            cin >> cards[i].fi;
            cards[i].se = i;
        }

        vector<pair<int, int>> original = cards;
        sort(cards.rbegin(), cards.rend());
        int last = n;
        for (auto card: cards) {
            if (card.se < last) {
                q.push(card.se);
                last = card.se;
            }
        }
        last = n;
        while (!q.empty()) {
            for (int i = q.front(); i < last; ++i) {
                cout << original[i].fi << " ";
            }
            last = q.front() ;
            q.pop();
        }

        cout << el;
    }
}
