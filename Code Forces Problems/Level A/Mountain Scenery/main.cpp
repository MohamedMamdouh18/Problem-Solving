#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)
 
 
int main() {
    IOS
    int n , k ;
    cin >> n >> k;
    int a[2*n+2] = {0} ;
    rep(i , 1 , 2*n+2)
    {
        cin >> a[i] ;
    }
 
    rep(i , 1 , 2*n+2)
    {
        if(k == 0)
        {
            break ;
        }
        else if(a[i] - a[i - 1] > 1 && a[i] - a[i + 1] > 1)
        {
            k -- ;
            a[i] -- ;
        }
    }
 
    rep(i , 1 , 2*n+2)
    {
        cout << a[i] << " " ;
    }
 
}
