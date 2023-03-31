#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
 
int main()
{
    int n , t = 0 ;
    cin >> n ;
    int a[n+1] ;
    vector <int> ones ;
    vector <int> twos ;
    vector <int> threes ;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ;
        if(a[i] == 1)
        {
            ones.pb(i) ;
        }
        else if(a[i] == 2)
        {
            twos.pb(i) ;
        }
        else
        {
            threes.pb(i) ;
        }
    }
    int num =min(min(ones.size() ,twos.size()) , threes.size() ) ;
    cout << num << endl ;
    for(int i = 0 ; i < num ; i ++)
    {
        cout << ones[i] <<" " <<twos[i] << " " <<threes[i] << endl ;
    }
}
