#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int t , m , n , x , y , total;
    string s ;
    cin >> t ;
    while(t--)
    {
        total = 0 ;
        cin >> m >> n >> x >> y ;
        rep(i , 0 , m)
        {
            cin >> s ;
            rep(j , 0 , n )
            {
                if(s[j] == s[j + 1] && s[j] == '.' && j != n-1)
                {
                    if(y < x * 2)
                    {
                        total += y ;
                        j++ ;
                    }
                    else
                    {
                        total += x * 2 ;
                        j ++ ;
                    }
                }
                else if(s[j] == '.')
                {
                    total += x;
                }
            }

        }
        cout << total << endl ;
    }
}
