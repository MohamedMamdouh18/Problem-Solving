#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int num ;
    vector<int> n ;
    int i = 0 ;
    while(num != 42)
    {
        cin >> num ;
        n.push_back(num) ;
        i ++ ;
    }
 
    for(int j = 0 ; j < i - 1 ; j ++)
    {
        cout << n[j] << endl ;
    }
}
