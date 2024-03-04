#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int n;
vector<int> A;
int cache[1001];

// from을 기준으로 from ~ 끝까지 감소하는 부분수열의 가장 긴 길이
int dec(int from) {
    int& ret = cache[from];
    if (ret != -1) return ret;

    if (from == n - 1) return 1;

    ret = 1;
    for (int next = from; next < n; ++next) if(A[from] > A[next]) ret = max(ret, 1 + dec(next));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    
    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, dec(i));
    cout << res << endl;
}