#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define llm LONG_LONG_MAX
#define el "\n"
#define se second
#define fi first
#define siz(ans) sizeof(ans) / sizeof(ans[0])
#define ll long long
#define all(a)  a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PREC cout.precision(20);
const ll mod = 1e9 + 7, N = 1e6;
bool prime[N] ;
void sieve(){
    prime[0] = prime[1] = true ;
    for (ll i = 2; i < N ; ++i) {
        if(!prime[i]){
            for (ll j = i*i; j < N; j+= i)
                prime[j] = true ;
        }
    }
}

void GREEN() {
    int n ;
    cin >> n ;
    if(!prime[n]){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << 1 << " ";
            cout << el ;
        }
    }else{
        int ones = n - 1 , spare;
        for (int i = 1; i < N; ++i) {
            if(prime[i] && !prime[ones + i] && !prime[1 + ones * i]){
                spare = i ;
                break;
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if(j != n-1) cout << 1 << " " ;
                else cout << spare << " " ;
            }
            cout << el ;
        }
        for (int i = 0; i < n -1; ++i) cout << spare << " " ;
        cout << 1 << el ;
    }

}

int main() {
    IOS
    PREC
    sieve() ;
    int tc = 1;
    cin >> tc;
    while (tc--) {
        GREEN();
    }
}
