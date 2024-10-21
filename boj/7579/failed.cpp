#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int cache[101][10000001];
vector<int> m, c;

int cost(int app, int mem) {
    int& ret = cache[app][mem];
    if (ret!=-1) return ret;

    ret = 987654321;
    ret = min(ret, cost(app+1, mem));
    ret = min(ret, c[app] + cost(app+1, mem - m[app]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    int n, M; cin >> n >> M; m.resize(n); c.resize(n);
    for (int i=0; i<n; i++) cin >> m[i] >> c[i];
    cout << cost(0, M) << endl;
}