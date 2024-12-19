#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<vector<int>> B;
vector<vector<int>> B2;
vector<int> A;

void rotateB2(int d) {
    if (d==0) return;
    vector<vector<int>> R;
    R.resize(n); for (int i=0; i<n; ++i) R[i].resize(n);
    if (d==1) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) R[n-1-j][i] = B2[i][j];
    else if (d==2) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) R[n-1-i][n-1-j] = B2[i][j];
    else if (d==3) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) R[j][n-1-i] = B2[i][j];
    B2 = R;
}

void slideB2() {
    vector<vector<int>> R;
    R.resize(n); for (int i=0; i<n; ++i) R[i].resize(n);
    for (int r=0; r<n; ++r) {
        int idx = 0;
        for (int i=0; i<n; ++i) {
            if (B2[r][i]!=0) {
                R[r][idx] = B2[r][i];
                idx++;
            }
        }
        for (int i=0; i<n-1; ++i) {
            if (R[r][i]==0) break;
            if (R[r][i]==R[r][i+1]) {
                R[r][i] *= 2;
                for (int j=i+1; j<n-1; ++j) R[r][j] = R[r][j+1];
                R[r][n-1] = 0;
            }
        }
    }
    B2 = R;
}

void moveB2(int d) {
    rotateB2(d);
    slideB2();
}

int maxInB2() {
    B2 = B;
    for (int a : A) {
        moveB2(a);
        // if (A[0]==2 && A[1]==1 && A[2]==0 && A[3]==3 && A[4]==2) {
        //     for (int a : A) cout << a << ' ';
        //     cout << endl;
        //     cout << a << endl;
        //     for (int i=0; i<n; ++i) {
        //       for (int j=0; j<n; ++j) cout << std::setfill(' ') << std::setw(4) << B2[i][j] << ' ';
        //       cout << endl;
        //     }
        //     cout << endl;
        // }
    }
    
    int ret = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) ret = max(ret, B2[i][j]);
    return ret;
}

int solve() {
    if (A.size()==5) return maxInB2();

    int ret = 0;
    for (int i=0; i<4; ++i) {
        A.push_back(i);
        ret = max(ret, solve());
        A.pop_back();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; B.resize(n);
    for (int i=0; i<n; ++i) {
        B[i].resize(n);
        for (int j=0; j<n; ++j) cin >> B[i][j];
    }
    cout << solve() << endl;
}