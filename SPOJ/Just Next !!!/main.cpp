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
        int n, flag = 0;
        cin >> n;
        vector<int> nums(n);
        vector<int> rem;
        for (auto &it: nums) cin >> it;

        for (int i = nums.size() - 1; i >= 1; --i) {
            if (nums[i] > nums[i - 1]) {
                flag = 1 ;
                rem.pb(nums[i]);
                sort(rem.begin(), rem.end());
                for (int j = 0; j < rem.size(); ++j) {
                    if(rem[j] > nums[i-1]){
                        swap(rem[j] , nums[i-1]) ;
                        break;
                    }
                }
                sort(rem.begin(), rem.end());
                for (int j = i; j < nums.size(); ++j) {
                    nums[j] = rem[j - i];
                }
                break;
            } else {
                rem.pb(nums[i]);
            }
        }

        if(!flag) {
            cout << -1 << el;
            continue ;
        }
        for (auto num: nums) cout << num ;
        cout << el;
    }
}
