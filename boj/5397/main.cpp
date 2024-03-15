#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

list<char> pwd;

int main() {
    int n; cin >> n;
    while(n--) {
        pwd.clear();
        auto cur = pwd.begin();
        string cmd; cin >> cmd;
        for (int i=0; i<cmd.size(); i++) {
            switch(cmd[i]) {
                case '<': {
                    if (cur != pwd.begin()) cur--;
                    break;
                }
                case '>': {
                    if (cur != pwd.end()) cur++;
                    break;
                }
                case '-': {
                    if (cur != pwd.begin()) cur = pwd.erase(--cur);
                    break;
                }
                default: {
                    cur = pwd.insert(cur, cmd[i]);
                    cur++;
                    break;
                }
            }
            // cout << cmd[i] << " ";
            // for (char c : pwd) cout << c;
            // cout << endl;
        }
        for (char c : pwd) cout << c;
        cout << endl;
    }
}