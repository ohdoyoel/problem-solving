#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cacheInc[1001];
int cacheDec[1001];
int n;
vector<int> A;

// 0 ~ to까지 증가하는 부분 수열
int inc(int to) {
    if (to < 0) return 0;
    
    int& ret = cacheInc[to];
    if (ret != -1) return ret;

    ret = 1;
    for (int i = 0; i < to; ++i) if (A[i] < A[to]) ret = max(ret, 1 + inc(i - 1));
    return ret;
}

// from ~ 끝까지 감소하는 부분 수열
int dec(int from) {
    if (from > 1000) return 0;
  
    int& ret = cacheDec[from];
    if (ret != -1) return ret;

    ret = 1;
    for (int i = from; i < n; ++i) if (A[from] > A[i]) ret = max(ret, 1 + dec(i + 1));
    return ret;
}

// from부터 끝까지의 가장 긴 바이토닉 부분 수열
int solve() {
    int ret = 1;
    for (int top = 0; top < n; ++top) {
        ret = max(ret, inc(top) + dec(top) - 1);
        cout << inc(top) + dec(top) - 1 << endl;
    }
    return ret;
}

int main() {
    memset(cacheInc, -1, sizeof(cacheInc));
    memset(cacheDec, -1, sizeof(cacheDec));
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << solve() << endl;
}