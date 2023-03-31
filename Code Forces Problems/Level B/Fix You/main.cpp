#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    int t ;
    cin >> t ;
    while(t--)
    {
        int r , c , counte = 0;
        cin >> r >> c ;
        char a[r][c] ;
        rep(i , 0 , r)
        {
            rep(j , 0 , c)
            {
                cin >> a[i][j] ;
                if(i == r-1)
                {
                    if(a[i][j] == 'D')
                    {
                        counte ++ ;
                    }
                }
                else if(j == c - 1)
                {
                    if(a[i][j] == 'R')
                    {
                        counte ++ ;
                    }
                }
            }
        }
        cout << counte << endl ;

    }
}
