#include <bits/stdc++.h>
using namespace std;

int main()
{
    string first_number , second_number ;
    cin >> first_number >> second_number ;
    int big_index , carries = 0 ;

    if(first_number.size() >= second_number.size())
    {
        big_index = first_number.size() ;
    }
    else
    {
        big_index = second_number.size() ;
    }

    reverse(first_number.begin() , first_number.end()) ;
    reverse(second_number.begin() , second_number.end()) ;

    vector<int> sum (big_index) ;

    for(int i = 0 ; i < big_index ; i ++)
    {
        if(i <= first_number.size() - 1 && i <= second_number.size() -1 )
        {
            sum[i] = first_number[i] + second_number[i] - '0' * 2 ;
        }
        else if(i <= first_number.size() - 1 && i > second_number.size() -1)
        {
            sum[i] = first_number[i] - '0' ;
        }
        else if(i > first_number.size() - 1 && i <= second_number.size() -1)
        {
            sum[i] = second_number[i] - '0' ;
        }
    }

    for(int i = 0 ; i < big_index ; i ++)
    {
        if(sum[i] > 9)
        {
            carries ++ ;
            if(i < big_index-1)
            {
                 sum[i + 1] += sum[i]/10 ;
            }

        }
    }

    cout << carries ;

}
