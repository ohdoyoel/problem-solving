#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

string s;
int idx;

string flip() {
    if (s[idx] == 'w' || s[idx] == 'b') return string(1, s[idx++]);

    idx++; // s[idx] is x
    vector<string> quad;
    for (int i=0; i<4; i++) quad.push_back(flip());
    return 'x' + quad[2] + quad[3] + quad[0] + quad[1];
}

int main() {
    int n; cin >> n;
    while(n--) {
        cin >> s;
        idx = 0;
        cout << flip() << endl;
    }
}