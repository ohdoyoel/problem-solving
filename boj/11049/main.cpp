#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using pii = pair<int, int>;

int n;
vector<pii> matrix;
int cache[501][501];

// s~e까지의 행렬 곱을 할 때 연산 최솟값 점화식: 적게 계산할 수 있는 것부터 계산하고, 나머지를 반환한다.
int solve(int s, int e) {
    int& ret = cache[s][e];
    if (ret != -1) return ret;

    if (s >= e) return ret = 0;
    else if (s+1 == e) ret = matrix[s].first + matrix[s].second + matrix[e].second;

    ret = 987654321;
    for (int m = s; m < e; ++m)
        ret = min(ret, solve(s, m) + matrix[s].first * matrix[m].second * matrix[e].second + solve(m+1, e));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    matrix.resize(n);
    for (int i = 0; i < n; ++i) cin >> matrix[i].first >> matrix[i].second;
    cout << solve(0, n-1) << endl;
}