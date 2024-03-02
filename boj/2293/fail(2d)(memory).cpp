#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[101][10001];
vector<int> kind;

// n~ 끝까지의 동전 종류를 보고 합이 k인 경우의 수
int solve(int n, int k) {
    if (k < 0) return 0;
    
    int& ret = cache[n][k];
    if (ret != -1)  return ret;
    
    if (k == 0) return ret = 1;
    if (n == sz(kind) - 1) return ret = !(k % kind[n]);

    ret = 0;
    for (int i = n; i < sz(kind); ++i) ret += solve(i, k - kind[i]);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n, k;
    cin >> n >> k;
    kind.resize(n);
    for (int i = 0; i < n; ++i) cin >> kind[i];
    cout << solve(0, k) << endl;
}