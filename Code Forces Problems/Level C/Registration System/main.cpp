#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define pb push_back
#define mp make_pair
#define srt(a)     (sort(a.begin() , a.end()))
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define minv(a)      (*min_element((a).begin(), (a).end()))
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define rep(i , a, b)    for(int i = a; i < b; i++)

int main(){
    IOS
    int n ;
    cin >> n ;
    map<string , int> a ;
    while(n --)
    {
        string s ;
        cin >> s ;
        if(a.find(s) != a.end())
        {
            cout<< s + to_string(a[s]) << endl ;
            a[s] ++ ;
        }
        else
        {
            a[s] = 1 ;
            cout<<"OK" <<endl ;
        }
    }

}
