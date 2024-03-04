#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;
#define MOD 10007

int cache[10][1001];

// tail로 끝났을 때 last 개의 자리를 채우는 오르막 수의 개수
int solve(int tail, int last) {
    int &ret = cache[tail][last];
    if (ret != -1) return ret;

    if (last == 0) return 1;

    ret = 0;
    for (int next = tail; next < 10; ++next) {
        ret += solve(next, last - 1);
        ret %= MOD;
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    cout << solve(0, n) << endl;
}