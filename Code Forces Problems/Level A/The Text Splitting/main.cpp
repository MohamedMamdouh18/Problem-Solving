#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n , p , q , order = 0 , flag = 0 , qi , pj;
    cin >> n >> p>> q;
    string s;
    cin >> s;

    rep(i , 0 , 100)
    {
        rep(j , 0 , 100)
        {
            if(s.size() == q*i + p*j)
            {
                flag = 1 ;
                qi = i ;
                pj = j ;
                i =100 ;
                j = 100 ;
            }
        }
    }
    if(!flag)
    {
        cout << -1 ;
        return 0 ;
    }
    cout << qi+pj << endl ;
    rep(i , 0 , pj)
    {
        cout << s.substr(order , p) << endl ;
        order += p ;
    }
    rep(i , 0 , qi)
    {
        cout << s.substr(order , q) << endl ;
        order += q ;
    }
}
