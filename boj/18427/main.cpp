#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[51][1001];
int n;
vector<vector<int>> H;

int block(int i, int height) {
    if (height==0) return 1;
    if (height<0 || i==n) return 0;

    int& ret = cache[i][height];
    if (ret != -1) return ret;

    ret = 0;
    ret += block(i+1, height);
    for (int h : H[i]) {
        ret += block(i+1, height-h);
        ret %= 10007;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    int m, h; cin >> n >> m >> h; H.resize(n);
    for (int i=-1; i<n; ++i) {
        string line; getline(cin, line);
        stringstream sstr(line);
        int num;
        while (sstr >> num) H[i].push_back(num);
    }
    // cout << H[2][0] << endl;
    cout << block(0, h) << endl;
}