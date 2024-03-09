#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using pcc = pair<char, char>;

pcc bracketPair[3] = {make_pair('(', ')'), make_pair('{', '}'), make_pair('[', ']')};

bool solve(string s) {
    stack<char> openStack;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            if (s[i] == bracketPair[j].first) openStack.push(s[i]);
            if (s[i] == bracketPair[j].second) {
                if (!openStack.empty() && openStack.top() == bracketPair[j].first) openStack.pop();
                else return false;;
            }
        }
    }
    return openStack.empty();
}

int main() {
    int n; cin >> n;
    while(n--) {
        string str; cin >> str;
        if (solve(str)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}