#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    int c; cin>>c;
    while (c--) {
        stack<int> S;
        string a; cin>>a;
        for (char c : a) {
            if (!S.empty() && ((S.top()=='(' && c==')') || (S.top()=='{' && c=='}') || (S.top()=='[' && c==']'))) S.pop();
            else S.push(c);
        }
        if (S.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}