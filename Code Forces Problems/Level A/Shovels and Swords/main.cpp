#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t ;
    cin >> t ;
    while(t --)
    {
        int a , b ;
        cin >> a >> b;
        cout << min(a , min(b , (a+b) / 3)) << endl ;
    }
}
