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
    ll n, x, health = 0;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        health += x;
        pq.push(x);
        if (health < 0) {
            while (health < 0 && !pq.empty()) {
                health += -pq.top();
                pq.pop();
            }
        }
    }


    cout << pq.size();
}
