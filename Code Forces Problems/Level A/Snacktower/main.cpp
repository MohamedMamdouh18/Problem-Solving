
#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define pb push_back
#define mp make_pair
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a , n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)


int main() {
    IOS
    int n , num;
    cin >> n ;
    int big = n ;
    priority_queue <int> a ;
    rep(i , 0 , n)
    {
        cin >> num ;
        a.push(num) ;
        if(a.top() == big)
        {
            while(!a.empty() && a.top() == big)
            {
                cout << a.top() << " " ;
                a.pop() ;
                big -- ;
            }
        }
        cout << endl ;
    }

}
