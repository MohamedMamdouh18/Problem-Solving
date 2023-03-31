#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define pb push_back
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define minv(a)      (*min_element((a).begin(), (a).end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    int n , k ;
    cin >> n >> k ;
    vector <int> a(n) ;
    vector <int> b ;
    int z[n] ;
    rep(i , 0 , n)
    {
        cin >> a[i] ;

    }
    int odd = 0 , even = 0 , cuts = 0;
    rep(i , 0 , n)
    {
        if(odd == even && i != 0)
        {
            b.pb(abs(a[i] - a[i-1])) ;
        }
        if(a[i] % 2==0)
        {
            even ++ ;
        }
        else
        {
            odd ++ ;
        }
    }
    srt(b) ;
    rep(i , 0 , b.size())
    {
        if(k - b[i] >= 0)
        {
            k -= b[i] ;
            cuts ++ ;
        }
        else
        {
            break ;
        }
    }
    cout<<cuts ;
}
