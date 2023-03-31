#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , a , no = 0;
    cin >> n ;

    while(n--)
    {
        cin >> a ;
        int arr[a] ;
        for(int i = 0 ; i < a ; i ++)
        {
            cin >> arr[i] ;
        }
        sort(arr , arr + a) ;
        for(int i = 0 ; i < a - 1 ; i ++)
        {
            if(abs(arr[i] - arr[i + 1] ) > 1 )
            {
                cout << "NO" << endl ;
                no = 1 ;
                break ;
            }
        }
        if(!no)
        {
            cout << "YES" << endl ;
        }
        no = 0 ;
    }

}
