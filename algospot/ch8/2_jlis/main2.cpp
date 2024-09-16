#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> A;
vector<int> B;
int cache[102][102];

// A[i], B[j] 중 1개를 포함한 이후의 jlis
int jlis(int i, int j) {
    if (i==A.size() || j==B.size()) return -987654321;

    int& ret = cache[i+1][j+1];
    if (ret != -1) return ret;
    
    int tail = 0;
    if (i!=-1 && j!=-1) tail = max(A[i], B[j]);
    else if (i==-1) tail = B[j];
    else if (j==-1) tail = A[i];

    int rest = 0;
    for (int a=i+1; a<A.size(); a++) if (tail < A[a]) rest = max(rest, jlis(a, j));
    for (int b=j+1; b<B.size(); b++) if (tail < B[b]) rest = max(rest, jlis(i, b));
    return ret = 1 + rest;
}

int main() {
    int c; cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        int a, b;
        cin >> a >> b; A.resize(a); B.resize(b);
        for (int i=0; i<a; i++) cin >> A[i];
        for (int i=0; i<b; i++) cin >> B[i];
        cout << jlis(-1, -1) - 1 << endl;
    }
}