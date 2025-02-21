#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<pair<int,int>> A;
vector<int> L, R;
int DP[301];

void buildLR() {
    sort(A.begin(), A.end());

    for (int i=0; i<n; ++i) {
        auto [x, h] = A[i];
        int idx = i;
        for (int j=i-1; j>=0; --j) {
            auto [_x, _h] = A[j];
            if (x-h<=_x) idx = j;
        }
        L[i] = idx;
        if (L[i]!=i) L[i] = L[idx];
    }

    for (int i=n-1; i>=0; --i) {
        auto [x, h] = A[i];
        int idx = i;
        for (int j=i+1; j<n; ++j) {
            auto [_x, _h] = A[j];
            if (_x<=x+h) idx = j;
        }
        R[i] = idx;
        if (R[i]!=i) R[i] = R[idx];
    }
}

int solve() {
    buildLR();

    DP[0] = 1;
    for (int i=1; i<n; ++i) {
        DP[i] = 987654321;

        if (L[i]-1<0) DP[i] = 1;
        else DP[i] = min(DP[i], 1 + DP[L[i]-1]);
        
        for (int j=0; j<i; ++j) {
            if (R[j] >= i) {
                if (j==0) DP[i] = 1;
                else DP[i] = min(DP[i], 1 + DP[j-1]);
            }
        }
    }
    
    // for (int i=0; i<n; ++i) {
    //   cout << L[i] << endl;
    //   cout << R[i] << endl;
    //   cout << DP[i] << endl;
    //   cout << endl;
    // }

    return DP[n-1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; A.resize(n); L.resize(n); R.resize(n);

    for (int i=0; i<n; ++i) {
        int x, h; cin >> x >> h;
        A[i] = {x, h};
    }

    cout << solve() << endl;
}