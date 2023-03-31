#include <bits/stdc++.h>
using namespace std ;

#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)
int f[1000000];

int main() {
    IOS
    int n , d ;
    cin >> n >> d ;
    vector<int> a(n) ;
    cinv(a) ;
    set<int> b ;
    int l = 0 , r = 0 , ml = 0, mr = 0 , length = -1;
    f[a[0]] ++ ;
    while(l < n)
    {
        while(r < n && b.size() <= d )
        {
            b.insert(a[r]) ;
            if(r-l > length)
            {
                ml = l + 1;
                mr = r + 1;
                length = r - l ;
            }
            r ++ ;
            b.insert(a[r]) ;
            if(r<n)f[a[r]] ++ ;
        }
        if(f[a[l]] == 1 )
        {
            b.erase(a[l]) ;
            f[a[l]] = 0 ;
        }
        else
        {
            f[a[l]] -- ;
        }
        l ++ ;
    }
    cout << ml << " " << mr ;

}
