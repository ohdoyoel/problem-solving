#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> A;
deque<int> D;

int main() {
    int n, l; cin >> n >> l; A.resize(n+1);
    for (int i=1; i<=n; i++) cin >> A[i];
    
    for (int i=1; i<=n; i++) {
        int least = A[i];
        for (int j=i; i-l>=0 && j>i-l; j--) least = min(least, A[j]);
        D.push_back(least);
    }

    for (int d : D) cout << d << " ";
    cout << endl;
}