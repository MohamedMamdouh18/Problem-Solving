#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{   int n , b , x , y;
    cin >> n ;
    vector<int> birds(n) ;
 
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> birds[i] ;
    }
 
    cin >> b ;
 
    for(int i = 0 ; i < b ; i ++)
    {
        cin >> x >> y ;
        if(x - 2 >= 0)
        {
            birds[x - 2] += y - 1 ;
        }
        if( x <= n - 1)
        {
            birds[x] += birds[x - 1] - y ;
        }
        birds[x - 1] = 0 ;
    }
 
    for(int i = 0 ; i < n ; i ++)
    {
        cout << birds[i] << endl ;
    }
 
}
