#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
int C[2][3], S[100001][3];

int maxScore() {
    for (int j=0; j<3; ++j) C[(n-1)%2][j] = S[n-1][j];
    for (int i=n-2; i>=0; --i) {
        for (int j=0; j<3; ++j) {
            int k = 0;
            if (j!=2) k = max(k, C[(i+1)%2][0]);
            k = max(k, C[(i+1)%2][1]);
            if (j!=0) k = max(k, C[(i+1)%2][2]);
            C[i%2][j] = S[i][j] + k;
        }
    }
    return max({C[0][0], C[0][1], C[0][2]});
}

int minScore() {
    for (int j=0; j<3; ++j) C[(n-1)%2][j] = S[n-1][j];
    for (int i=n-2; i>=0; --i) {
        for (int j=0; j<3; ++j) {
            int k = 987654321;
            if (j!=2) k = min(k, C[(i+1)%2][0]);
            k = min(k, C[(i+1)%2][1]);
            if (j!=0) k = min(k, C[(i+1)%2][2]);
            C[i%2][j] = S[i][j] + k;
        }
    }
    return min({C[0][0], C[0][1], C[0][2]});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) for (int j=0; j<3; ++j) cin >> S[i][j];
    cout << maxScore() << ' ';
    cout << minScore();
}