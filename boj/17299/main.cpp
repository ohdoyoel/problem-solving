#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int F[1000001];
vector<int> A;
stack<int> noNGF;
vector<int> NGF;

int main() {
    memset(F, 0, sizeof(F));
    int n; cin >> n; A.resize(n); NGF.resize(n);
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        A[i] = a;
        F[a]++;
    }

    for (int i=0; i<n; i++) {
        while(!noNGF.empty() && F[A[noNGF.top()]] < F[A[i]]) {
            NGF[noNGF.top()] = A[i];
            noNGF.pop();
        }
        noNGF.push(i);
    }

    while(!noNGF.empty()) {
        NGF[noNGF.top()] = -1;
        noNGF.pop();
    }

    for(int ngf : NGF) cout << ngf << " ";
    cout << endl;
}