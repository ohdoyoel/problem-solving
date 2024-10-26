#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1001][3][3];
int n;
vector<vector<int>> C;

int cost(int i, int before, int first) {
    if (i==n-1) {
        int res = 987654321;
        for (int j=0; j<3; ++j) if (j!=before && j!=first) res = min(res, C[i][j]);
        return res;
    }

    int& ret = cache[i][before][first];
    if (ret != -1) return ret;

    ret = 987654321;
    for (int j=0; j<3; ++j) if (before!=j) ret = min(ret, C[i][j] + cost(i+1, j, first));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n; C.resize(n);
    for (int i=0; i<n; i++) {
        C[i].resize(3);
        cin >> C[i][0] >> C[i][1] >> C[i][2];
    }
    int res = 987654321;
    res = min(res, C[0][0] +cost(1, 0, 0));
    res = min(res, C[0][1] + cost(1, 1, 1));
    res = min(res, C[0][2] + cost(1, 2, 2));
    cout << res << endl;
}