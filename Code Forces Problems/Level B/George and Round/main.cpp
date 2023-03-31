#include <bits/stdc++.h>

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    IOS
    int n , m ;
    cin >> n >> m ;
    vector<int> req(n) ;
    vector<int> have(m) ;
    for (int i = 0; i < n; ++i) {
        cin >> req[i] ;
    }
    for (int i = 0; i < m; ++i) {
        cin >> have[i] ;
    }
    int  l = 0 ,  r = 0;

    while(l < have.size() && r < req.size())
    {
        if(have[l] >= req[r]) r ++ ;
        l ++ ;
    }

    cout << req.size()-r  ;
}
