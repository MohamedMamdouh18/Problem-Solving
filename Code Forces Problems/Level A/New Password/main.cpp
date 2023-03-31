#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main()
{
  int n , k ;
  cin >> n >> k ;
  char first = 'a' ;
  string s ;
  for(int i = 0 ; i < k ; i ++)
  {
      s.pb(first + i) ;
  }
  int order = 0;
  while(n--)
  {
      cout<<s[order] ;
      order ++ ;
      if(order == k)
      {
          order = 0 ;
      }
  }
}
