#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[1001][10001];
vector<int> price;

// n~끝까지 보고, 남은 카드 개수는 r개일 때 최대 가격
int solve(int n, int r) {
    int& ret = cache[n][r];
    if (ret != -1) return ret;

    if (r == 0) return ret = 0;

    ret = 0;
    for (int i = n; i <= sz(price); ++i)
        if (i <= r) ret = max(ret, solve(i + 1, r - i));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    price.resize(n);
    for (int i = 0; i < n; ++i) cin >> price[i];
    cout << solve(0, n) << endl;
}