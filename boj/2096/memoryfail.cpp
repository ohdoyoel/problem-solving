#include<bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int n;
int cache[100001][3];
vector<vector<int>> nums;

// r, c에서 출발해서 얻을 수 있는 최대 합
int maxSum(int r, int c) {
    int &ret = cache[r][c];
    if (ret != -1) return ret;

    if (r == n - 1) return ret = nums[r][c];

    ret = nums[r][c];
    for (int d = -1; d <= 1; ++d) if (0 <= c+d && c+d <= 2) ret = max(ret, nums[r][c] + maxSum(r+1, c+d));
    return ret;
}

// r, c에서 출발해서 얻을 수 있는 최소 합
int minSum(int r, int c) {
    int &ret = cache[r][c];
    if (ret != -1) return ret;

    if (r == n - 1) return ret = nums[r][c];

    ret = 987654321;
    for (int d = -1; d <= 1; ++d) if (0 <= c+d && c+d <= 2) ret = min(ret, nums[r][c] + minSum(r+1, c+d));
    return ret;
}

int main() {
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        nums[i].resize(3);
        for (int j = 0; j < 3; ++j) cin >> nums[i][j];
    }
    memset(cache, -1, sizeof(cache));
    cout << max({maxSum(0, 0), maxSum(0, 1), maxSum(0, 2)}) << endl;
    memset(cache, -1, sizeof(cache));
    cout << min({minSum(0, 0), minSum(0, 1), minSum(0, 2)}) << endl;
}