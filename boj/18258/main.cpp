#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    queue<string> q;
    while(n--) {
        string cmd; cin >> cmd;
        if (cmd == "push") {
            string p; cin >> p;
            q.push(p);
        }
        else if (cmd == "pop") {
            if (q.size() == 0) {
                cout << -1 << endl;
                continue;
            }
            string p = q.front(); cout << p << endl; q.pop();
        }
        else if (cmd == "size") cout << q.size() <<endl;
        else if (cmd == "empty") cout << q.empty() <<endl;
        else if (cmd == "front") {
            if (q.size() == 0) {
                cout << -1 << endl;
                continue;
            }
            string p = q.front();
            cout << p << endl;
        }
        else if (cmd == "back") {
            if (q.size() == 0) {
                cout << -1 << endl;
                continue;
            }
            string p = q.back();
            cout << p << endl;
        }
    }
}