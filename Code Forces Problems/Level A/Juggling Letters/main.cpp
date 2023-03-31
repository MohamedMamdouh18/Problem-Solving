#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t , n  , a , no = 0;
  cin >> t ;
  while(t--)
  {
      vector <int> counte = {0} ;
      string s ;
      string m ;
      cin >> n ;
      a = n ;
      while(a--)
      {
          cin >> m ;
          s.append(m) ;
      }
      for(int i = 'a' ; i <= 'z' ; i ++)
      {
          if(count(s.begin() , s.end() , i))
          {
              counte.push_back(count(s.begin() , s.end() , i)) ;
          }
      }

      for(int i = 0 ; i < counte.size() ; i ++)
      {
          if(counte[i] % n != 0)
          {
              cout << "NO" << endl ;
              no = 1 ;
              break ;
          }
      }
      if(!no)
      {
          cout << "YES" << endl ;
      }
      no = 0 ;
  }
}
