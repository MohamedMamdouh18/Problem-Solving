#include <bits/stdc++.h>
using namespace std ;

#define vi vector<int>
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define coutv(a)     for(int i=0; i<a.size() ; i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    vi a(6) ;
    cinv(a) ;
    int sume = sum(a) ;
    rep(i , 0 , 6)
    {
        rep(j , 0 , 6)
        {
            rep(m , 0 , 6)
            {
                if(i != j && j != m && i != m)
                {
                    if( (a[i] + a[j] +a[m]) * 2 ==sume)
                    {
                        cout <<"yes" ;
                        return 0 ;
                    }
                }
            }
        }
    }
    cout <<"no" ;
}
