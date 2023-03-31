#include <bits/stdc++.h>
using namespace std;
 
vector <int> nums ;
 
void in_nums()
{
    for(int i = 0 ; i < 500 ; i ++)
    {
        for(int j = 0 ; j < 500 ; j ++)
        {
            nums.push_back(i*2020 + j *2021) ;
        }
    }
    sort(nums.begin() , nums.end()) ;
}
 
int main()
{
    in_nums() ;
    int t ;
    cin >> t ;
    int n ;
    while(t--)
    {
        cin >> n ;
        if(binary_search(nums.begin() , nums.end() , n))
        {
            cout << "yes" <<endl ;
        }
        else
        {
             cout << "no" <<endl ;
        }
    }
 
}
