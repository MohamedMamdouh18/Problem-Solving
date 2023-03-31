#include <bits/stdc++.h>
using namespace std ;

#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main() {
    IOS
    int n ;
    cin >> n ;
    int order = n ;
    queue <pair<string , int>> s ;
    s.push(mp("" , 0)) ;
    while(1)
    {
        string p = s.front().first ;
        int c = s.front().second ;
        s.pop() ;
        if(p.size() == n * 2)
        {
            if(c == 0)
            {
                cout << p << endl;
            }
        }
        else if(p.size() > n * 2)
        {
            return 0 ;
        }
        s.push(mp(p + "(" , c + 1)) ;
        if(c > 0)
        {
            s.push(mp(p + ")" , c - 1)) ;
        }
    }
}
