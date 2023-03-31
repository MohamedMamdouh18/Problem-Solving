#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define pb push_back
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define minv(a)      (*min_element((a).begin(), (a).end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main(){
    IOS
    int n , step = 0;
    cin >> n ;
    while(n > 0)
    {
        if(n-5 >= 0)
        {
            n -= 5 ;
            step ++ ;
        }
        else if(n-4 >= 0)
        {
            n -= 4 ;
            step ++ ;
        }
        else if(n-3 >= 0)
        {
            n -= 3 ;
            step ++ ;
        }
        else if(n-2 >= 0)
        {
            n -= 2 ;
            step ++ ;
        }
        else if(n-1 >= 0)
        {
            n -= 1 ;
            step ++ ;
        }
    }
    cout << step ;

}
