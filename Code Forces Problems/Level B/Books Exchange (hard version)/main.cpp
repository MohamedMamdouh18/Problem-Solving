#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define vi vector<int>
#define srt(a)     (sort(a.begin() , a.end()))
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<vector<int>> adj_list;
vector<int> ans;
int n;

int dfs(int node, int target, int days) {
    if (node == target) return ans[node] = days;

   return ans[node] = dfs(adj_list[node][0] , target , days + 1) ;
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        adj_list.clear();
        adj_list.resize(n);
        ans.clear();
        ans.resize(n, 0);
        rep(i, 0, n) {
            int x;
            cin >> x;
            x--;
            adj_list[i].pb(x);
        }

        rep(i, 0, n) {
            if (ans[i] == 0) {
                dfs(adj_list[i][0], i, 1);
            }
        }
        rep(i, 0, n) cout << ans[i] << " ";
        cout << endl;
    }
}
