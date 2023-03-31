#include <bits/stdc++.h>
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n , k , cnt = 0 ,  differ = 0;
    cin >> n >> k ;
    string s ;
    cin >> s ;
    int l = 0 , r = 0 , a = 0 , b = 0;
    if(n == 1)
    {
        cout << 1 ;
        return 0 ;
    }
    else if(n == k)
    {
        cout << n ;
        return 0 ;
    }

    while(r < n)
    {
        if(s[r] == 'a') a++ ;
        if(a <= k) cnt = max(cnt , r-l+1) ;
        while(a > k)
        {
            if(s[l] == 'a') a-- ;
            l ++ ;
        }
        r++ ;
    }
    l = 0 ; r = 0 ;
    while(r < n)
    {
        if(s[r] == 'b') b++ ;
        if(b <= k) cnt = max(cnt , r-l+1) ;
        while(b > k)
        {
            if(s[l] == 'b') b-- ;
            l ++ ;
        }
        r++ ;
    }
    cout << cnt ;
}
