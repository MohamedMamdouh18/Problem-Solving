#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    string a ;string b ;
    cin >> a >> b ;
    int order = 0 ;
    while(a[order] == '0')
    {
        order ++ ;
    }
    a = a.substr(order) ;
    order = 0 ;
    while(b[order] == '0')
    {
        order ++ ;
    }
    b = b.substr(order) ;

    if(a.size() > b.size())
    {
        cout << ">" ;
    }
    else if(a.size() < b.size())
    {
        cout << "<" ;
    }
    else
    {
        rep(i , 0 , a.size())
        {
            if(a[i] > b[i])
            {
                cout << ">" ;
                return 0 ;
            }
            else if(a[i] < b[i])
            {
                cout << "<" ;
                return 0 ;
            }
        }
        cout << "=" ;
    }

}
