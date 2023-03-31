#include <bits/stdc++.h>
using namespace std ;
 
#define pb push_back
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define minv(a)      (*min_element((a).begin(), (a).end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define rev_v(a)  (reverse(a.begin() , a.end()))
#define rev_ar(a,size)   (reverse(a , a+size))
#define sort(a)     (sort(a.begin() , a.end()))
#define prntar(a,s)     for(int i=0; i<s ; i++){cout<<a[i];}
#define bsrch(a , n)    (binary_search(a.begin() , a.end() , n))
#define memar(a)     (memset(a ,0 ,sizeof(a)))
#define rep(i, n)        for(int i = 0; i < n; i++)
#define repf(i, a, b)    for(int i = a; i < b; i++)
#define veci        vector<int>
 
int main() {
    int t , num1 , num2 ;
    cin >> t ;
    while(t--)
    {
        cin >> num1 >> num2 ;
        if(num1 == 1)
        {
            cout << num2 << endl ;
        }
        else if(num1 == num2)
        {
            cout << 1 << endl ;
        }
        else if (num2 > num1)
        {
            long double nume = num2 ;
            cout << (int) ceil(nume / num1) <<endl ;
        }
        else
        {
            if(num1 % num2 == 0)
            {
                cout << 1 << endl ;
            }
            else
            {
                cout << 2 << endl ;
            }
        }
    }
}
