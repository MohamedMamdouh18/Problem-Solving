#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , w , h , a , pieces;
    cin >> n ;
    while(n--)
    {
        pieces = 1 ;
        cin >> w >> h >> a ;
        while(w % 2 == 0)
        {
            pieces *= 2 ;
            w /= 2 ;
        }
        while(h % 2 == 0)
        {
            pieces *= 2 ;
            h /= 2 ;
        }


        if(pieces >= a)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl ;
        }
    }
}
