#include <bits/stdc++.h>
using namespace std ;

int main() {
    int t ;
    cin >> t ;
    int a[t] ;
    for(int i = 0 ; i < t ; i ++)
    {
        cin >> a[i] ;
    }
    for(int i = 0 ; i < t ; i ++)
    {
        for(int j = 0 ; j < t ; j ++)
        {
            if(a[j] == i+1)
            {
                cout << j+1 << " " ;
                break ;
            }
        }
    }
}
