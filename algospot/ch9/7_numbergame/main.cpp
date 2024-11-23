#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MIN = -987654321;
int cache[51][51];
int n;
vector<int> A;

int scoreDiff(int start, int end) {
    if (start>=end) return 0;

    int& ret = cache[start][end];
    if (ret != MIN) return ret;

    ret = MIN;
    ret = max(ret, A[start]-scoreDiff(start+1, end));
    ret = max(ret, A[end-1]-scoreDiff(start, end-1));
    if (end-start >= 2) {
        ret = max(ret, -scoreDiff(start+2, end));
        ret = max(ret, -scoreDiff(start, end-2));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c; cin >> c;
    while (c--) {
        for (int i=0; i<51; ++i) for (int j=0; j<51; ++j) cache[i][j]=MIN;
        cin >> n; A.resize(n);
        for (int i=0; i<n; ++i) cin >> A[i];
        cout << scoreDiff(0, n) << endl;
    }
}