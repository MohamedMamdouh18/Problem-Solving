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
    string n;
    cin >> n ;
    int count0 = 0 , count1 = 0;
 
    rep(i , 0 , n.size())
    {
        if(n[i] == '0')
        {
            count1 = 0;
            count0 ++ ;
        }
        else
        {
            count0 = 0 ;
            count1 ++ ;
        }
        if(count0 == 7 || count1 == 7)
        {
            cout << "YES" ;
            return 0 ;
        }
    }
    cout << "NO" ;
}
