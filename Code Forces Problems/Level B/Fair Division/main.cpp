#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int main() {
    IOS
    int n , t , sum1 , sum2, num ;
    cin >> n ;
    while(n--)
    {
        sum1 = 0 ;
        sum2 = 0 ;
        cin >> t ;
        while(t--)
        {
            cin >> num ;
            if(num == 1) sum1++;
            else sum2 ++ ;
        }
        if( (sum1%2 == 0 && sum1 != 0 )|| (sum1%2 == 0 && sum2%2==0)  )
        {
            cout << "yes" << endl ;
        }
        else
        {
            cout << "no" << endl ;
        }
    }


}
