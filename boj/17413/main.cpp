#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

stack<char> s;

int main() {
    string str; getline(cin,str);
    for (int i=0; i<=str.size(); i++) {
        if (str[i]==' ' || i==str.size()) {
            while(!s.empty()) {
                cout << s.top();
                s.pop();
            }
            if (i!=str.size()) cout << str[i];
        }
        
        else if (str[i] == '<') {
            while(!s.empty()) {
                cout << s.top();
                s.pop();
            }
            while(str[i] != '>') {
                cout << str[i];
                i++;
            }
            cout << str[i];
        }
        
        else s.push(str[i]);
    }
}