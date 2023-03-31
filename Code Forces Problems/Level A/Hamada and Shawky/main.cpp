#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n , result;
    long double k ;
    cin >> n >> k ;

    if( k == 1)
    {
        cout << -1 ;
    }
    else if (k > n)
    {
        cout << 0 ;
    }
    else
    {
        --k  ;
        result = ceil((n-k) / k) ;
        cout << result ;
    }
}
