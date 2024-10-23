#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[1001][4];
int n;
vector<vector<int>> C;
int first;

int cost(int i, int before) {
    if (i==n-1) return (first==before) + 1;

    int& ret = cache[i][before+1];
    if (ret != -1) return ret;

    ret = 987654321;
    for (int j=0; j<3; j++) if (before!=i) ret = min(ret, C[i][j]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i=0; i<n; i++) cin >> C[i][0] >> C[i][1] >> C[i][2];
    cout << cost(0, -1) << endl;
}