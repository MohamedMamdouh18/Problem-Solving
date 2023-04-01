#include <bits/stdc++.h>
using namespace std;
#define rev(a)  (reverse(a.begin() , a.end()))
#define memar(a , n)     (memset(a ,n ,sizeof(a)))
#define pb push_back

int main() {
    string s1 ;string s2 ;
    while(cin>> s1)
    {
        cin >> s2 ;
        if(s1 == "0" || s2 == "0")
        {
            cout << 0 << endl;
            continue ;
        }

        int size1 = s1.size() ; int size2 = s2.size() ;
        int a[size1 + size2] ;
        memar(a , 0) ;
        rev(s1) ; rev(s2) ;
        for(int i = 0 ; i < size1 ; i ++)
        {
            for(int j = 0 ; j < size2 ; j ++)
            {
                a[i + j] += (s1[i] - '0') * (s2[j] - '0') ;
                if(a[i + j] >= 10)
                {
                    a[i + j + 1] += a[i + j] / 10 ;
                    a[i + j] %= 10 ;
                }
            }
        }
        reverse(a , a+size1+size2) ;
        for(int i = 0 ; i < size1 + size2 ; i ++)
        {
            if(a[i] == 0 && i ==0) continue ;
            cout << a[i] ;
        }
        cout << endl ;
    }
}
