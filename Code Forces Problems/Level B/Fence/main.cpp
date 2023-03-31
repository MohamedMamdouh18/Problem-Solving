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
    int n , width ;
    cin >> n >> width ;
    int a[n+1] , s[n+1];
    a[0] = 0 ; s[0] = 0;
    rep(i , 1 , n + 1 )
    {
        cin >> a[i] ;
        s[i] = a[i] + s[i-1];
    }
    ll mini , height = 2e62;
    rep(i , width , n + 1)
    {
        if(s[i] - s[i-width] < height)
        {
            height = s[i] - s[i-width] ;
            mini = i-width+1 ;
        }
    }
    cout << mini ;
 
}
