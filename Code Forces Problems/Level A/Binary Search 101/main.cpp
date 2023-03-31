#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a , b , k ;
    cin >> a >> b >> k ;

    long long start = a , ende = b , mid , steps = 0 ;

    while (start <= ende)
    {
        steps ++ ;
        mid = (start + ende) / 2 ;
        if(mid == k)
        {
            cout << steps ;
            return 0 ;
        }
        else if (mid > k)
        {
            ende = mid - 1 ;
        }
        else if (mid < k)
        {
            start = mid + 1 ;
        }
    }
}
