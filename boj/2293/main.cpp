#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[10001];
vector<int> kind;

// 모든 동전 종류를 보고 합이 k인 경우의 수
int solve(int k) {
    cache[0] = 1;

    for (int i = 0; i < sz(kind); ++i)
        for (int s = kind[i]; s <= k; ++s)
            cache[s] += cache[k - kind[i]];
    
    return cache[k];
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n, k;
    cin >> n >> k;
    kind.resize(n);
    for (int i = 0; i < n; ++i) cin >> kind[i];
    cout << solve(k) << endl;
}