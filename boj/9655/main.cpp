#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[1001];

// n개가 남았을 때 게임의 진행 최소 횟수
int iter(int n) {
    int& ret = cache[n];
    if (ret != -1) return ret;

    if (n == 0) return 0;

    return ret = min(1 + iter(n - 1), 1 + iter(n - 3));
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    if (iter(n) % 2) cout << "SK" << endl;
    else cout << "CY" << endl;
}