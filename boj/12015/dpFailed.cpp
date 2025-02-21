#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<int> A;
int D[1000001];

int solve() {
    D[n-1] = 1;
    for (int i=n-2; i>=0; --i) {
        int mx = 0;
        for (int j=i+1; j<=n-1; ++j) if (A[i]<A[j]) mx = max(mx, 1+D[j]);
        D[i] = mx;
    }
    return D[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; A.resize(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    cout << solve() << endl;
}