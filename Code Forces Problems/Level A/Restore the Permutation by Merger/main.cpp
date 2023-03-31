#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n , s , found = 0;
        cin >> n ;
        n *= 2 ;
        vector <int> a ;
        for(int i = 0 ; i < n ; i ++)
        {
            cin >> s ;
            for(int j = 0 ; j < a.size() ; j ++)
            {
                if(s == a[j])
                {
                    found = 1 ;
                    break ;
                }
            }
            if(!found)
            {
                a.push_back(s) ;
            }
            found = 0 ;
        }
        for(int i = 0 ; i < a.size() ; i ++)
        {
            cout << a[i] << " " ;
        }
        cout << endl ;
    }
}
