#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[1000001];

int solve(int n) {
    if (n < 0) return 0;

    int& ret = cache[n];
    if (ret != -1) return ret;

    if (n == 0) return ret = 0;
    if (n == 1) return ret = 1;
    if (n == 2) return ret = 2;

    return ret = solve(n - 2) + solve(n - 1);
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    cout << solve(n) << endl;
}