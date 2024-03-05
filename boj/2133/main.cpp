#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[31];

// 3xn을 채우는 경우의 수
int solve(int n) {
    int& ret = cache[n];
    if (ret != -1) return ret;

    if (n % 2) ret = 0;
    if (n == 3) 

    return ret = pow(solve(n / 2), 2);
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << solve(n) << endl;
}