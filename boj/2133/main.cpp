#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[31];

// 3 x n 을 채우는 경우의 수
int solve(int n) {
    int& ret = cache[n];
    if (ret != -1) return ret;

    if (n % 2) return ret = 0;
    else if (n == 0) return ret = 1;
    else if (n == 2) return ret = 3;

    ret = solve(2) * solve(n - 2);
    for (int i = 4; i <= n; ++i) ret += 2 * solve(n - i);
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << solve(3, n) << endl;
    cout << solve(2, 4);
}