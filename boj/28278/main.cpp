#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

stack<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    while(n--){
        int cmd; cin >> cmd;
        switch(cmd) {
            case 1: {
                int x; cin >> x;
                s.push(x);
                break;
            } case 2: {
                if (s.empty()) {
                    cout << -1 << endl;
                    break;
                }
                cout << s.top() << endl;
                s.pop();
                break;
            } case 3: {
                cout << s.size() << endl;
                break;
            } case 4: {
                cout << s.empty() << endl;
                break;
            } case 5: {
                if (s.empty()) {
                    cout << -1 << endl;
                    break;
                }
                cout << s.top() << endl;
                break;
            }
        }
    }
}