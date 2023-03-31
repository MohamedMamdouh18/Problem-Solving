
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n , dist = 0 , d;
    char s ;
    long long total ;
    cin >> n >> total;
    while(n--)
    {
        cin >> s >> d ;
        if(s == '+')
        {
            total += d ;
        }
        else
        {
            if((d) <= total)
            {
                total -= d ;
            }
            else
            {
                dist ++ ;
            }
        }
    }
    cout << total<< " " << dist ;
}
