#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t , yes = 0;
    cin >> t ;
    long long n ;
    while(t--)
    {
        cin >> n ;
        while(n > 1)
        {
            if(n % 2 == 1)
            {
                cout << "YES" << endl ;
                yes = 1 ;
                break ;
            }
            n /= 2 ;
        }
        if(!yes)
        {
            cout << "NO" << endl;
        }
        yes = 0 ;
    }

}
