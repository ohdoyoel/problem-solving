#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool isGood(string str) {
    stack<char> s;
    for (int i=0; i<str.size(); i++) {
        if (s.empty()) {
            s.push(str[i]);
            continue;
        }
        if (s.top() != str[i]) s.push(str[i]);
        else s.pop();
    }

    return s.empty();
}

int main() {
    int n; cin >> n;

    int ret = 0;
    while (n--) {
        string str; cin >> str;
        if (isGood(str)) ret++;
    }
    cout << ret << endl;
}