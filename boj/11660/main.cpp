#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (uint)(x).size()
using namespace std;

int cache[1025][1025];
vector<vector<int>> table;

int accmtSum(int x, int y) {
    if (x < 0 || y < 0) return 0;
    
    int& ret = cache[x][y];
    if (ret != -1) return ret;

    if (x == 0 && y == 0) return ret = table[0][0];
    else if (x == 0) return ret = table[0][y] + accmtSum(0, y - 1);
    else if (y == 0) return ret = table[x][0] + accmtSum(x - 1, 0);

    return ret = table[x][y] + accmtSum(x - 1, y) + accmtSum(x, y - 1) - accmtSum(x - 1, y - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

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
        // cout << accmtSum(x2 - 1, y2 - 1) << endl;
        cout << accmtSum(x2 - 1, y2 - 1) - accmtSum(x1 - 2, y2 - 1) - accmtSum(x2 - 1, y1 - 2) + accmtSum(x1 - 2, y1 - 2) << endl;
    }
}

// cache[][] - cache[][]로 부분합을 구할 수 있다!
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);  시간 초과 개중요