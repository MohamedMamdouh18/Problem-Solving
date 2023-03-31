#include <bits/stdc++.h>
using namespace std;

#define mina(a)      (*min_element((a).begin(), (a).end()))
#define maxa(a)      (*max_element((a).begin(), (a).end()))
#define cnt(a,i)  (count(a.begin() , a.end() , i))


int main()
{
    int n , t , k , d ;
    cin >> n >> t >> k >> d ;
    int raw_time = (n+k-1) / k;
    if(raw_time == 1)
    {
        cout << "NO" ;
        return 0 ;
    }

    int f_oven = 0 ; int s_oven = d ;
    for(int i = 0 ; i < raw_time ; i ++)
    {
        if(f_oven <= s_oven)
        {
            f_oven += t ;
        }
        else
        {
            s_oven += t ;
        }
    }

    if(max(f_oven , s_oven) >= raw_time*t)
    {
         cout << "NO" ;
    }
    else
    {
         cout << "YES" ;
    }

}
