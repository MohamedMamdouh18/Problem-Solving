#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , orders;
    cin >> n ;
    vector<int> arr(n) ;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> arr[i] ;
    }

    cin >> orders ;
    int operations , number ;

    for(int i = 0 ; i < orders/2 ; i ++)
    {
        cin >>operations >> number ;
        if(operations == 1)
        {
            arr.push_back(number) ;
        }
        else
        {
            arr.insert(arr.begin() , number) ;
        }
    }


    for(int i = 0 ; i < orders/2 ; i ++)
    {
        cin >> number ;
        if(number == 3)
        {
            arr.insert(arr.begin() , arr[arr.size() - 1] ) ;
            arr.pop_back() ;
        }
        else
        {
            arr.push_back(arr.front() );
            arr.erase(arr.begin()) ;
        }

    }

    cout << arr.size() << endl;

    for(int i = 0 ; i < arr.size() ; i ++ )
    {
        cout << arr[i] <<" " ;
    }

}
