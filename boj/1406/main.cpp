#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    string str; cin >> str;
    list<char> line;
    for (int i = 0; i < str.size(); ++i) line.push_back(str[i]);
    for(char c : line) cout << c;
    cout << endl;
    int n; cin >> n;
    int cursur = 0;
    while(n--) {
        char cmd; cin >> cmd; cout << cmd;
        if (cmd == 'L') if (cursur > 0) cursur--;
        else if (cmd == 'D') if (cursur <= n) cursur++;
        else if (cmd == 'B') if (cursur > 0) {
            line.erase(next(line.begin(), cursur-1));
            cursur--;
        }
        else if (cmd == 'P') {
            char x; cin >> x;
            line.insert(next(line.begin(), cursur), x);
        }
        for(char c : line) cout << c;
        cout << endl;
    }
    for(char c : line) cout << c;
}