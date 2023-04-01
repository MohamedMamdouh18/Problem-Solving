#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    while(1)
    {
        long long bulbs;
        cin >> bulbs ;
        if(bulbs == 0)
        {
            return 0 ;
        }
        long long sqr = sqrt(bulbs) ;
        if(sqr * sqr == bulbs)
        {
            cout << "yes" << endl ;
        }
        else{
            cout << "no" << endl ;
        }
    }
}
