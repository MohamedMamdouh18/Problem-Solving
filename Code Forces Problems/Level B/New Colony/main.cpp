#include <bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a , n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)     (sort(a.begin() , a.end()))
#define rev(a)  (reverse(a.begin() , a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define coutv(a)     for(int i=0; i<a.size() ; i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)
 
int main() {
    IOS
    int t ;
    cin >> t ;
    while(t --)
    {
        ll n , k  , order = 0 , the_loop = 1 , place = -1 , flag = 1;
        cin >> n >> k ;
        vector<int> a(n) ;
        cinv(a) ;
        while(the_loop)
        {
            rep(i , 0 , n - 1)
            {
                if(a[i] < a[i+1])
                {
                    if(k > 1)
                    {
                        k -- ;
                        a[i] ++ ;
                    }
                    else
                    {
                        place = i + 1 ;
                        the_loop = 0 ;
                    }
                    flag = 0 ;
                    break ;
                }
            }
            if(flag)
            {
                break ;
            }
            flag = 1 ;
        }
        cout << place << endl ;
 
    }
}
