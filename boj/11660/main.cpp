#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[1025][1025][1025][1025];
vector<vector<int>> table;

int partialSum(int x1, int y1, int x2, int y2) {
    int& ret = cache[x1][y1][x2][y2];
    if (ret != -1) return ret;

    if (x1 == x2 && y1 == y2) return table[x1][y1];

    int xHalf = (x2 - x1) / 2;
    int yHalf = (y2 - y1) / 2;
    return ret = partialSum(x1, y1, x1 + xHalf, y1 + yHalf)
                + partialSum(x1, y1 + yHalf, x1 + xHalf, y2)
                + partialSum(x1 + xHalf, y1, x2, y1 + yHalf)
                + partialSum(x1 + xHalf, y1 + yHalf, x2, y2);
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n, m;
    cin >> n >> m;
    table.resize(n);
    for (int i = 0; i < n; ++i) {
        table[i].resize(n);
        for (int j = 0; j < n; ++j) cin >> table[i][j];
    }
    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << partialSum(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endl;
    }
}