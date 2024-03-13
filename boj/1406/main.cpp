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
    list<char>::iterator cursur = line.end();
    while(n--) {
        char cmd; cin >> cmd; cout << cmd;
        if (cmd == 'L') if (cursur > line.begin()) cursur--;
        else if (cmd == 'D') if (cursur < line.end()) cursur++;
        else if (cmd == 'B') {
            if (cursur > line.begin()) line.erase(--cursur);
        }
        else if (cmd == 'P') {
            char x; cin >> x;
            line.insert(cursur, x);
        }
        for(char c : line) cout << c;
        cout << endl;
    }
    for(char c : line) cout << c;
}