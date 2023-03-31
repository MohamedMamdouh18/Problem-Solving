#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    long long x , y , p , restaurant , distance , least_x = 10000000001 , least_y =10000000001 , least_p = 10000000001 , least_distance = 10000000001, number , best;
    cin >> number ;

    for(int i = 0 ; i < number ; i ++)
    {
        cin >> x >> y >> p;
        distance = sqrt(pow(x , 2) + pow(y , 2)) ;
        if(distance < least_distance )
        {
            best = i + 1 ;
            least_x = x ;
            least_y = y ;
            least_p = p ;
            least_distance = distance ;
        }
        else if(distance == least_distance &&p < least_p )
        {
            best = i + 1 ;
            least_x = x ;
            least_y = y ;
            least_p = p ;
            least_distance = distance ;
        }
        else if(distance == least_distance &&p == least_p && x < least_x)
        {
            best = i + 1 ;
            least_x = x ;
            least_y = y ;
            least_p = p ;
            least_distance = distance ;
        }
        else if(distance == least_distance &&p == least_p && x == least_x && y <= least_y)
        {
            best = i + 1 ;
            least_x = x ;
            least_y = y ;
            least_p = p ;
            least_distance = distance ;
        }
    }

    cout << best ;

}
