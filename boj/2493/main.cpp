#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> h;
vector<int> res;
stack<int> s;

int main() {
    int n; cin >> n; h.resize(n); res.resize(n);
    for (int i=0; i<n; i++) cin >> h[i];

    for (int i=n-1; i>=0; i++) {
        while(!s.empty() && h[s.top()] < h[i]) {
            res[s.top()] = i+1;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()) {
        res[s.top()] = 0;
        s.pop();
    }

    for (int r : res) cout << r << " ";
    cout << endl;
}