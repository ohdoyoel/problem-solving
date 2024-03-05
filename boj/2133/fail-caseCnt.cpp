#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[2][31];

// r x n 을 채우는 경우의 수
int solve(int r, int n) {
    int& ret = cache[r - 2][n];
    if (ret != -1) return ret;

    // 2 x n
    if (r == 2) {
        if (n == 0 || n == 1) return ret = 1;
        return ret = solve(r, n - 1) + solve(r, n - 2);
    }

    // 3 x n
    if (n % 2) return ret = 0;
    else if (n == 0) return ret = 1;
    else if (n == 2) return ret = 3;
    return ret = 2*(solve(2,n-2) + 2*solve(2,n-3) + 2*solve(3,n-4) - 3*solve(2,n-4) + solve(3,n-2)) - solve(3,n-4);
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n; cin >> n;
    cout << solve(3, n) << endl;
    cout << solve(2, 4);
}