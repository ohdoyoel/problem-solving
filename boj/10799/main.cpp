#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int main() {
    string b; cin >> b;
    stack<int> openIdx;
    int ret = 0;
    for (int i = 0; i < sz(b); ++i) {
        if (b[i] == '(') openIdx.push(i);
        else {
            if (openIdx.top() == i-1) ret += openIdx.size() - 1;
            else ret += 1;
            openIdx.pop();
        }
    }
    cout << ret << endl;
}