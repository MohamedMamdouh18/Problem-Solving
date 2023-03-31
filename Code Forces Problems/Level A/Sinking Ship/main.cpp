#include <bits/stdc++.h>
using namespace std ;

#define pb push_back
#define ll long long
#define vi vector<int>
#define isfind(a,s)  a.find(s) != a.npos
#define rep(i , a, b)    for(int i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
   IOS
   int n ;
   cin >> n ;
   string s1 , s2;
   string cap ;
   vector<string> women ;
   vector<string> rat ;
   vector<string> men ;
   rep(i , 0 , n)
   {
       cin >> s1 >> s2 ;
       if(s2 == "captain") cap = s1 ;
       else if(s2 == "woman" || s2 == "child") women.pb(s1) ;
       else if(s2 == "rat") rat.pb(s1) ;
       else if(s2 == "man") men.pb(s1) ;
   }

   rep(i , 0 ,rat.size()) cout << rat[i] << endl ;
   rep(i , 0 ,women.size()) cout << women[i] << endl ;
   rep(i , 0 ,men.size()) cout << men[i] << endl ;
   cout << cap ;
}
