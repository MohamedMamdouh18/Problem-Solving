#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , b , d , num , sum = 0 , times = 0;
    cin >> n >> b >> d ;

    for(int i = 0 ; i < n ; i ++)
    {
        cin >> num ;
        if(num > b)
        {
            continue ;
        }
        else
        {
            sum += num ;
        }

        if(sum > d)
        {
            times ++ ;
            sum = 0 ;
        }
    }

    cout << times ;

}

