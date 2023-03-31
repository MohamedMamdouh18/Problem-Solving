#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define pb push_back
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define minv(a)      (*min_element((a).begin(), (a).end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))

int main() {
    IOS
    int t , maxi, mini , n = 0;
    cin >> t ;
    vector <int> a(t) ;
    for(int i = 0 ; i < t ; i ++)
    {
        cin >> a[i] ;
    }
    mini = minv(a) ; maxi = maxv(a) ;
    for(int i = 0 ; i < t ; i ++)
    {
        if(a[i] > mini && a[i] < maxi)
        {
            n ++ ;
        }
    }
    cout << n ;
}
