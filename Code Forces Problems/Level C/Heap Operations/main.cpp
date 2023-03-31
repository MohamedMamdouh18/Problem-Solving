#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define el "\n"
#define se second
#define fi first
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main() {
    IOS
    priority_queue<int , vector<int> , greater<>> pq ;
    queue<string> operations ;
    int t ;
    cin >> t ;
    while(t --){
        string s ; int x ;
        cin >> s ;
 
        if(s == "insert"){
            cin >> x ;
            pq.push(x) ;
            operations.push(s + " " + to_string(x)) ;
        }else if(s == "getMin"){
            cin >> x ;
            if(!pq.empty() && x == pq.top()) operations.push(s + " " + to_string(x)) ;
            else{
                while(!pq.empty()){
                    if(x <= pq.top()) break ;
                    operations.push("removeMin");
                    pq.pop() ;
                }
 
                if(!pq.empty() && x == pq.top()) operations.push(s + " " + to_string(x)) ;
                else{
                    pq.push(x) ;
                    operations.push("insert " + to_string(pq.top()));
                    operations.push("getMin " + to_string(pq.top()));
                }
            }
        }else{
            if(pq.empty()){
                pq.push(0) ;
                operations.push("insert " + to_string(0));
            }
            pq.pop() ;
            operations.push("removeMin");
        }
    }
 
    cout << operations.size() << el ;
    while(!operations.empty()){
        cout << operations.front() << el ;
        operations.pop() ;
    }
}
