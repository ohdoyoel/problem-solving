#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

stack<int> s;
vector<int> A;
vector<int> nge;

int main() {
    int n; cin >> n; A.resize(n); nge.resize(n);
    for(int i=0; i<n; i++) cin >> A[i];

    for (int i=0; i<n; i++) {
        while(!s.empty() && A[s.top()] < A[i]) {
            nge[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()) {
        nge[s.top()] = -1;
        s.pop();
    }
    
    for (int i=0; i<n; i++) cout << nge[i] << " ";
    cout << endl;
}