#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// c : 0~i, 0~j의 lcs
int c[1001][1001];
string A, B;

void solve() {
    c[0][0] = A[0]==B[0];
    for (int i=1; i<A.size(); ++i) c[i][0] = max(c[i-1][0], A[i]==B[0] ? 1 : 0);
    for (int j=1; j<B.size(); ++j) c[0][j] = max(c[0][j-1], A[0]==B[j] ? 1 : 0);

    for (int i=1; i<A.size(); ++i) {
        for (int j=1; j<B.size(); ++j) {
            if (A[i]==B[j]) c[i][j] = 1 + c[i-1][j-1];
            else c[i][j] = max(c[i][j-1], c[i-1][j]);
            
        }
    }
    cout << c[A.size()-1][B.size()-1] << endl;
}

void print(int i, int j) {
    if (A[i]==B[j]) {
        if (i>0 && j>0) print(i-1, j-1);
        cout << A[i];
        return;
    }
    if (c[i-1][j] > c[i][j-1]) print(i-1, j);
    else print(i, j-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> A >> B;
    solve();
    print(A.size()-1, B.size()-1);
}