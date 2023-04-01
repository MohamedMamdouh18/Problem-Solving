#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int t , reverse = 0;
    deque<int> dq;
    cin >> t;
    while (t--) {
        string s ;
        cin >> s ;
        if(s == "back"){
            if(dq.empty()) cout << "No job for Ada?" << el ;
            else{
                if(!reverse){
                    cout << dq.back() << el;
                    dq.pop_back() ;
                }
                else{
                    cout << dq.front() << el;
                    dq.pop_front() ;
                }
            }
        }else if(s == "front"){
            if(dq.empty()) cout << "No job for Ada?" << el ;
            else{
                if(!reverse){
                    cout << dq.front() << el;
                    dq.pop_front() ;
                }
                else{
                    cout << dq.back() << el;
                    dq.pop_back() ;
                }
            }
        }else if(s == "reverse"){
            reverse = !reverse ;
        }else if(s == "push_back"){
            int x ;
            cin >> x ;
            if(!reverse){
                dq.push_back(x) ;
            }else{
                dq.push_front(x) ;
            }
        }else{int x ;
            cin >> x ;
            if(!reverse){
                dq.push_front(x) ;
            }else{
                dq.push_back(x) ;
            }
        }
    }
}
