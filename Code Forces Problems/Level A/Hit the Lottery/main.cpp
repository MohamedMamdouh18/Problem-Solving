#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , bills = 0;
    cin >> n ;

    if(n >= 100)
    {
        bills += n / 100 ;
        n %= 100 ;
    }
    if(n >= 20 )
    {
        bills += n / 20 ;
        n %= 20 ;
    }
    if(n >= 10 )
    {
        bills += n / 10 ;
        n %= 10 ;
    }
    if(n >= 5)
    {
        bills += n / 5 ;
        n %= 5 ;
    }
    if(n >= 1)
    {
        bills += n / 1 ;
    }

    cout << bills << endl ;

}
