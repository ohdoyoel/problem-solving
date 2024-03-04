#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int n;
vector<int> A;
int cache[1001];

// from ~ 끝까지 증가하는 부분 수열의 가장 큰 합
int solve(int from) {
    int& ret = cache[from];
    if (ret != -1) return ret;

    if (from == n - 1) return ret = A[n - 1];

    ret = A[from];
    for (int next = from; next < n; ++next) if (A[from] < A[next]) ret = max(ret, A[from] + solve(next));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << solve(0) << endl;
}